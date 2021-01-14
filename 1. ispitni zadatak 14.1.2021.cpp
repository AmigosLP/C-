#include<iostream>
using namespace std;
void funkcijaZaSve();
int main()
{
    /*
	Napisati program u kojem je potrebno unijeti odabrani broj cifara počevši od cifre
	najveće težinske vrijednosti, pa od njih sastaviti i ispisati prirodni broj. Unos cifara
	se prekida kada se unese broj manji od 0, ukoliko korisnik unese cifru vecu od 9, ispisati
	poruku da cifra nije validna, ali se unos ne prekida. (Obavezno koristiti bar jednu korisnički
	definisanu funkciju).

		Ispis neka bude oblika:

		Upisi cifru: 2
		Upisi cifru: 8
		Upisi cifru: 72
		Cifra nije validna
		Upisi cifru: -1
		Broj sastavljen od zadanih cifara je 28.
	
	
	*/

	funkcijaZaSve();


	cin.get();
	return 0;
}
void funkcijaZaSve()
{
	int broj,suma=0;
	do
	{
		cout << "Upisi cifru : ";
		cin >> broj;
		if (broj > 9 || broj<0)
		{
			cout << "Broj nije validan." << endl;
		}
		else
		suma = suma * 10 + broj;
	} while (broj>0);
	cout << "Broj sastavljen je : " << suma << endl;
}
