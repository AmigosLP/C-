/*
Napisati program u kojem je potrebno unijeti odabrani broj cifara počevši od cifre najveće težinske vrijednosti, 
pa od njih sastaviti i ispisati prirodni broj.Unos cifara se prekida kada se unese broj manji od 0, u
koliko korisnik unese cifru vecu od 9, ispisati poruku da cifra nije validna, ali se unos ne prekida. 
(Obavezno koristiti bar jednu korisnički definisanu funkciju).
Ispis neka bude oblika :
Upisi cifru : 2
Upisi cifru : 8
Upisi cifru : 72
Cifra nije validna
Upisi cifru : -1
Broj sastavljen od zadanih cifara je 28.
*/
#include<iostream>
using namespace std;
void sastavi(int,int&);
int main()
{
    int x, rezultat=0;
	do
	{
		cout << "Upisi cifru: ";
		cin >> x;
		if (x > 9)
		{
			cout << "Cifra nije validna!" << endl;
		}
		else if(x>0)
		{
			sastavi(x, rezultat);
		}
	} while (x >= 0);

	cout << "Broj sastavljen od zadadnih cifara je " << rezultat << endl;

	cin.get();
	return 0;
}
void sastavi(int n,int& rezultat)
{
	rezultat = rezultat * 10 + n;
	//2,8
	//0=0*10+2
	//2=2*10+8
	//28
	
}
