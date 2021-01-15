#include<iostream>
using namespace std;
void provjera(int&, int&);
bool prost(int);
void glavna(int);
void petlje(int, int);
int main()
{
    /*
		Svaki paran broj se može prikazati kao suma dva prosta broja (tkz. Goldbachovo pravilo).
		Napisati program koji će najprije učitati dva prirodna broja n1 i n2 (n2 > n1).
		Zatim prikazati sve parne brojeve u intervalu od n1 do n2 kao sumu dva prosta broja.
		U glavnom programu samo
		unijeti navedena dva prirodna broja i pozvati funkciju koja obavlja zadani posao.
	*/
	int broj1, broj2;
	cout << "Unesite prvi broj : " << endl;
	cin >> broj1;
	cout << "Unesite drugi broj : " << endl;
	cin >> broj2;
	provjera(broj1, broj2);
	petlje(broj1, broj2);

	cin.get();
	return 0;
}
void provjera(int& broj1, int& broj2)
{
	if (broj1 > broj2)
	{
		int temp = broj2;
		broj2 = broj1;
		broj1 = temp;
	}
}
bool prost(int broj)
{
	if (broj == 1)
		return false;
	for (int i = 2; i <= broj / 2; i++)
	{
		if (broj % i == 0)
			return false;
	}
	return true;
}
void glavna(int broj)
{
	for (int i = broj / 2, j = broj / 2; i < broj; i++, j--)
	{
		if (prost(i) && prost(j))
		{
			cout << broj << " = " << i << " + " << j << endl;
			break;//moze, ali i ne treba
		}
	}
}
void petlje(int broj1, int broj2)
{
	if (broj1 % 2 != 0)
		broj1++;
	for (int i = broj1; i <= broj2; i += 2)
	{
		glavna(i);
	}
}
