#include<iostream>
using namespace std;

//#define POINTERS_BASICS
#define POINTERS_AND_ARRAYS

void main()
{
	setlocale(LC_ALL, "Rus");

#ifdef POINTERS_BASICS
	int a = 2;
	int* pa = &a;
	cout << a << endl;//¬ывод значени€ переменной "а".
	cout << &a << endl;//¬з€тие адреса переменной "а" пр€мо при выводе.
	cout << pa << endl;//¬ывод адреса переменной "а" хран€щегос€ в указателе "ра".
	cout << *pa << endl;//–азыменование казател€ "ра", и получение значени€ по адресу.

	int* pb;
	int b = 3;
	pb = &b;
	cout << b << endl;
	cout << &b << endl;
	cout << *pb << endl;
#endif // POINTERS_BASICS

#ifdef POINTERS_AND_ARRAYS
	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
#endif // POINTERS_AND_ARRAYS
}