
#include "kalman.h"

/*	
	Q:����������Q���󣬶�̬��Ӧ��죬�����ȶ��Ա仵
	R:����������R���󣬶�̬��Ӧ�����������ȶ��Ա��	
*/

double KalmanFilter(const double ResrcData,
					double ProcessNiose_Q,double MeasureNoise_R,double InitialPrediction,int i)
{
	double R = MeasureNoise_R;
	double Q = ProcessNiose_Q;

	static	double x_last[3];
  static	double p_last[3];

	double x_mid = x_last[i];
	double x_now;

	

	double p_mid ;
	double p_now;
	double kg;

	x_mid=x_last[i]; //x_last=x(k-1|k-1),x_mid=x(k|k-1)
	p_mid=p_last[i]+Q; //p_mid=p(k|k-1),p_last=p(k-1|k-1),Q=����
	kg=p_mid/(p_mid+R); //kgΪkalman filter��RΪ����
	x_now=x_mid+kg*(ResrcData-x_mid);//���Ƴ�������ֵ
		
	p_now=(1-kg)*p_mid;//����ֵ��Ӧ��covariance	

	p_last[i] = p_now; //����covarianceֵ
	x_last[i] = x_now; //����ϵͳ״ֵ̬

	return x_now;		
}





