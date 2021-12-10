#pragma once
#include <cmath>
#include <cstdlib>
#include <ctime> 
#include <iostream>
using namespace std;
class mes
{
public:
	const double PI = std::acos(-1);
	int N;
	const double u = 7.2921158553e-5;
	double phi = 0;
	double xi1 = 0;
	double delta = PI / 2;
	double psi = PI / 6;
	double* r;
	double* z;
	mes() { r = NULL; N = 0; z = 0; };
	~mes() { delete[] r; r = NULL; };
	mes(int N);

};

