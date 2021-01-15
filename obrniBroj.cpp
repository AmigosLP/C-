#include <iostream>

/*
 * Omogućiti unos dva prirodna broja A i B (A>100000, B>50000). Napisati program koji će kreirati i ispisati broj C koji će se sastojati od cifara broja A u obrnutom redoslijedu ali bez cifara koje se pojavljuju u broju B. Obavezno koristiti bar jednu funkciju. Ispsati razliku brojeva A i C.
 */

using namespace std;

int brojC(int A, int B);

bool isIsto(int B, int cifra);

int main()
{
    int A, B;

	do
	{
		cout << "Unesite A: ";
		cin >> A;
		cout << "Unesite B: ";
		cin >> B;
		
	} while (A < 100000 && B < 50000);

	int C = brojC(A, B);

	cout << "Broj A u obrnutom redoslijedu bez cifara B je: " << C << endl;
	
	return 0;
}

int brojC(int A, int B)
{
	int C = 0;

	while (A > 0)
	{
		int cifra = A % 10;

		if (!isIsto(B, cifra))
		{
			C = C * 10 + cifra;
		}

		A /= 10;
	}

	return C;
}

bool isIsto(int B, int cifra)
{
	while (B > 0)
	{
		int cifraB = B % 10;

		if (cifraB == cifra)
			return true;

		B /= 10;
	}

	return false;
}
