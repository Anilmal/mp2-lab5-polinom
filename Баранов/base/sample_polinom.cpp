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
	cout << "������� ��������" << endl;
	cin >> n;
	Polinom pol(n);
	cout << "������� �����: "<<pol.Calculate(1, 2, 3) << endl;
	pol.Show();
	return 0;
}