#pragma once
#include "time.h"
#include "math.h"
#include "cstdlib"
using namespace std;

struct Monom
{
	double coef;
	int step;
	double x;
	Monom(int st=0,double _x=0)
	{
		x = _x;
		step = st;
		coef = 0.1*(rand()%9+1);
	}
	Monom& operator=(const Monom &tmp)
	{
		coef = tmp.coef;
		step = tmp.step;
		return *this;
	}
	bool operator==(const Monom &tmp)
	{
		if ((coef == tmp.coef) && (step == tmp.step))
			return true;
		else
			return false;
	}
	double Calculate()
	{
		double res = pow(x, step)*coef;
		return res;
	}
};