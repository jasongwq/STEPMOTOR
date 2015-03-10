//=====================================================================================================
// IMU.c
// S.O.H. Madgwick
// 25th September 2010
//=====================================================================================================
// Description:
//
// Quaternion implementation of the 'DCM filter' [Mayhony et al].
//
// User must define 'halfT' as the (sample period / 2), and the filter gains 'Kp' and 'Ki'.
//
// Global variables 'q0', 'q1', 'q2', 'q3' are the quaternion elements representing the estimated
// orientation.  See my report for an overview of the use of quaternions in this application.
//
// User must call 'IMUupdate()' every sample period and parse calibrated gyroscope ('gx', 'gy', 'gz')
// and accelerometer ('ax', 'ay', 'ay') data.  Gyroscope units are radians/second, accelerometer
// units are irrelevant as the vector is normalised.
//
//=====================================================================================================
//----------------------------------------------------------------------------------------------------
// Header files
#include "IMU.h"
#include <math.h>
//----------------------------------------------------------------------------------------------------
// Definitions
#define Kp 0.5f       // proportional gain governs rate of convergence to accelerometer/magnetometer
#define Ki 0.0001//0.008f//0.008f     // integral gain governs rate of convergence of gyroscope biases
#define halfT 0.001f  // half the sample period(s)

#define Gyro_Gr     0.0010653f
#define Gyro_G      0.0610351                                //���ٶȱ�ɶ� �˲�����Ӧ������2000��ÿ��
//#define Gyro_G 0.060975
//#define Gyro_Gr        0.0010653                                //���ٶȱ�ɻ��� �˲�����Ӧ������2000��ÿ��
//����+-2000   16bit
//4000/65536=0.06103515625 ��/LSB
//---------------------------------------------------------------------------------------------------
// Variable definitions
float q0 = 1, q1 = 0, q2 = 0, q3 = 0; // quaternion elements representing the estimated orientation
float exInt = 0, eyInt = 0, ezInt = 0;// scaled integral error
//====================================================================================================
// Function
//====================================================================================================
T_float_angle   Att_Angle;  //ATT�������������̬��
//float position_x=0,position_y=0,position_z=0;
float compass_yaw;
float AngleOffset_Rol=0,AngleOffset_Pit=0;
void IMUupdate(S_INT16_XYZ *gyr, S_INT16_XYZ *acc, T_float_angle *angle)
{
    float ax = acc->x, ay = acc->y, az = acc->z;
    float gx = gyr->x, gy = gyr->y, gz = gyr->z;
    float norm;
    float vx, vy, vz;
    float ex, ey, ez;
    gx *= Gyro_Gr;
    gy *= Gyro_Gr;
    gz *= Gyro_Gr;
    // normalise the measurements
    norm = sqrt(ax * ax + ay * ay + az * az);
    ax = ax / norm;
    ay = ay / norm;
    az = az / norm;
    // �ѼӼƵ���ά����ת�ɵ�λ������
    // estimated direction of gravity
    vx = 2 * (q1 * q3 - q0 * q2);
    vy = 2 * (q0 * q1 + q2 * q3);
    vz = q0 * q0 - q1 * q1 - q2 * q2 + q3 * q3;
    // ���ǰ���Ԫ������ɡ��������Ҿ����еĵ����е�����Ԫ�ء�
    // �������Ҿ����ŷ���ǵĶ��壬��������ϵ������������ת����������ϵ��������������Ԫ�ء�
    // ���������vx\y\z����ʵ���ǵ�ǰ��ŷ���ǣ�����Ԫ�����Ļ����������ϵ�ϣ����������������λ������
    // error is sum of cross product between reference direction of field and direction measured by sensor
    ex = (ay * vz - az * vy);
    ey = (az * vx - ax * vz);
    ez = (ax * vy - ay * vx);
    // axyz�ǻ����������ϵ�ϣ����ٶȼƲ����������������Ҳ����ʵ�ʲ����������������
    // axyz�ǲ����õ�������������vxyz�����ݻ��ֺ����̬����������������������Ƕ��ǻ����������ϵ�ϵ�����������
    // ������֮�������������������ݻ��ֺ����̬�ͼӼƲ��������̬֮�����
    // ������������������������Ҳ�������������ˣ�����ʾ��exyz�����������������Ĳ����
    // �����������Ծ���λ�ڻ�������ϵ�ϵģ������ݻ������Ҳ���ڻ�������ϵ�����Ҳ���Ĵ�С�����ݻ����������ȣ����������������ݡ���������Լ��ö�������һ�£����������ǶԻ���ֱ�ӻ��֣����Զ����ݵľ�������ֱ�������ڶԻ�������ϵ�ľ�����
    // integral error scaled integral gain
    exInt = exInt + ex * Ki;
    eyInt = eyInt + ey * Ki;
    ezInt = ezInt + ez * Ki;
    // adjusted gyroscope measurements
    gx = gx + Kp * ex + exInt;
    gy = gy + Kp * ey + eyInt;
    gz = gz + Kp * ez + ezInt;
    // �ò���������PI����������ƫ
    // integrate quaternion rate and normalise
    q0 = q0 + (-q1 * gx - q2 * gy - q3 * gz) * halfT;
    q1 = q1 + (q0 * gx + q2 * gz - q3 * gy) * halfT;
    q2 = q2 + (q0 * gy - q1 * gz + q3 * gx) * halfT;
    q3 = q3 + (q0 * gz + q1 * gy - q2 * gx) * halfT;
    // ��Ԫ��΢�ַ���
    // normalise quaternion
    norm = sqrt(q0 * q0 + q1 * q1 + q2 * q2 + q3 * q3);
    q0 = q0 / norm;
    q1 = q1 / norm;
    q2 = q2 / norm;
    q3 = q3 / norm;
    // ��Ԫ���淶��
    static float Yaw_I = 0;
    Yaw_I = (gyr->z * Gyro_G *0.01);
    angle->yaw =angle->yaw + Yaw_I;// (0.99) * (angle->yaw + Yaw_I) + (0.01) * (compass_yaw);
    //angle->yaw = atan2(2 * q1 * q2 + 2 * q0 * q3, -2 * q2*q2 - 2 * q3* q3 + 1)* 57.3; // yaw
    angle->pit = asin(-2 * q1 * q3 + 2 * q0 * q2) * 57.3; // pitch
    angle->rol = -atan2(2 * q2 * q3 + 2 * q0 * q1, -2 * q1 * q1 - 2 * q2 * q2 + 1) * 57.3; // roll
    //��Ԫ��ת����ŷ����

}
////====================================================================================================
//// END OF CODE
////====================================================================================================
////////////////////////////////////////////////////////////////////////////////

