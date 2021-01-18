#include <iostream>

using namespace std;

/*
Napisati program u kojem je potrebno unijeti odabrani broj cifara počevši od cifre najveće težinske vrijednosti, pa od njih sastaviti i ispisati prirodni broj. 
Unos cifara se prekida kada se unese broj manji od 0, ukoliko korisnik unese cifru vecu od 9, ispisati poruku da cifra nije validna, ali se unos ne prekida.
(Obavezno koristiti bar jednu korisnički definisanu funkciju).

Ispis neka bude oblika:

Upisi cifru: 2
Upisi cifru: 8
Upisi cifru: 72
Cifra nije validna
Upisi cifru: -1
Broj sastavljen od zadanih cifara je 28.

*/
void funkcija(int broj);
int main() 
{

	
	int broj = 0;
	int rezultat = 0;
	do {	
		
		if (broj > 9) {
			cout << "Cifra nije validna." << endl;

		}
		else 
		{
			rezultat = rezultat * 10 + broj;
		}

		cout << "Unesite cifre: " << endl;
		cin >> broj;
	

	} while (broj >= 0);

	funkcija(rezultat);

}
void funkcija(int rezultat) {

	cout << "Broj sastavljenih cifara je: " << rezultat << endl;
}
