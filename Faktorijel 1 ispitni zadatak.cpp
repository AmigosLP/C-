/*
Poštujući sve faze procesa programiranja, napisati program koji korisniku omogućava unos cijelog broja N, te izračunava vrijednost sume faktorijela neparnih brojeva u intervalu [1, N]. 
Suma faktorijela prikazana je sljedećom formulom: S = 1! + 3! + 5! + ... + N!
*/

#include <iostream>
using namespace std;
int faktorijel(int);
int sumafaktorijel(int);
int main()
{
    int N;

	cout << "Unesite N= ";
	cin >> N;

	cout << "Faktorijel je " << faktorijel(N) << endl;
	cout<<"Suma faktorijela je " << sumafaktorijel(N) << endl;


	cin.get();
	return 0;
}
int faktorijel(int n)
{
	int F = 1;
	for (int i = 1; i <= n; i++)
	{
		F *= i;
	}
	return F;
}
int sumafaktorijel(int n)
{
	int s = 0;
	for (int i = 1; i <= n; i++)
	{
		s += faktorijel(i);
	}
	return s;

}
