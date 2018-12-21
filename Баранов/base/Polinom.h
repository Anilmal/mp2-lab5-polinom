#ifndef __POLINOM_H__
#define __POLINOM_H__
#include <string>
#include "DatList.h"
#include "Monom.h"
#include "time.h"
#include "cstdlib"

using namespace std;
class  Polinom
{
	int pow_order;
	DatList<int>steps_monoms;
	DatList<double>coef_monm;
public:
	 Polinom(int _pow=0)
	 {
		 pow_order = _pow;
	 }
	 double Calculate(double x,double y,double z)
	 {
		 DatList<double> monoms;
		 int  counts=0;
		 double res=0;
		 double mon_res = 1;
		 for (int i = 0; i < pow_order; i++)
		 {
			 int tmp = rand() % pow_order;
			 steps_monoms.Push(tmp);
			 Monom elem(tmp, x);
			 monoms.Push(elem.Calculate());
			 tmp = rand() % pow_order;
			 steps_monoms.Push(tmp);
			 Monom elem_1(tmp, y);
			 monoms.Push(elem_1.Calculate());
			 tmp = rand() % pow_order;
			 steps_monoms.Push(tmp);
			 Monom elem_2(tmp, z);
			 monoms.Push(elem_2.Calculate());
			 coef_monm.Push(elem.coef*elem_1.coef*elem_2.coef);
   		 }
		 while (!monoms.IsEmpty())
		 {
			 if (counts!= 3)
			 {
				 double d = monoms.Get();
				 monoms.Pop(monoms.GetSize()-1);
				 mon_res *= d;
				 counts++;
			 }
			 if (counts == 3)
			 {
				 res += mon_res;
				 counts = 0;
			 }
		 }
		 return res;
	 }
	 void Show()
	 {
		 int counts=1;
		 while (!coef_monm.IsEmpty() && !steps_monoms.IsEmpty())
		 {
			 double tmp1 = coef_monm.Get();
			 coef_monm.Pop(coef_monm.GetSize() - 1);
			 if (counts == 1)
			 {
				 cout << tmp1 << '*' << 'x'<<'^'<<steps_monoms.Get()<<'*';
				 steps_monoms.Pop(steps_monoms.GetSize() - 1);
				 counts++;
			 }
			 if (counts == 2)
			 {
				 cout << tmp1 << '*' << 'y' << '^' <<steps_monoms.Get()<<'*';
				 steps_monoms.Pop(steps_monoms.GetSize() - 1);
				 counts++;
			 }
			 if (counts == 3)
			 {
				 cout << tmp1 << '*' << 'z' << '^' << steps_monoms.Get();
				 steps_monoms.Pop(steps_monoms.GetSize() - 1);
				 if (!steps_monoms.IsEmpty())
					 cout << '+';
				 counts = 1;
			 }
		 }
		 cout << endl;
	 }

};
#endif