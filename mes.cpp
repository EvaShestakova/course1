#include "mes.h"
mes::mes(int N) { 
	this->N = N; 
	r = new double[N]; 
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		r[i] = 0.001*(rand() % 41 - 20)*PI/180/3600; 
		//cout << r[i]<< ' ';
	}
	z = new double[N];
	cout << '\n';
	for (int i = 0; i < N; i++)
	{
		z[i] = -u * cos(phi) * sin(i * delta) * sin(psi) + u * cos(phi) * cos(i * delta) * cos(psi) + r[i];
		//cout << z[i] << ' ';
	}
	cout << '\n';
	
	double a1=0,b1=0,a2=0,b2=0,c=0,d=0;
	for (int i = 0; i < N; i++)
	{
		a1 += (-u * cos(phi) * sin(i * delta))* (-u * cos(phi) * sin(i * delta));
		b1 += (-u * cos(phi) * sin(i * delta)) * u * cos(phi) * cos(i * delta) ;
		a2 += (-u * cos(phi) * sin(i * delta)) * u * cos(phi) * cos(i * delta) ;
		b2 += u * cos(phi) * cos(i * delta)  * u * cos(phi) * cos(i * delta);
		c += -u * cos(phi) * sin(i * delta)  * z[i];
		d += u * cos(phi) * cos(i * delta) * z[i];
	}
	double det = a1 * b2 - b1 * a2;
	cout << atan(((b2 * c - b1 * d) / (-a2 * c + a1 * d)))*180/PI;
}