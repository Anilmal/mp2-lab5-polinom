#include "iostream"
#include "DatList.h"
#include "Monom.h"
#include "Polinom.h"
#include "locale.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Степень Полинома" << endl;
	cin >> n;
	Polinom pol(n);
	cout << "Полином равен: "<<pol.Calculate(1, 2, 3) << endl;
	pol.Show();
	return 0;
}