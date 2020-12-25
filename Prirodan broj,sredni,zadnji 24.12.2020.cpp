#include <iostream>
using namespace std;
/*
* /* a) Omogućiti korisniku unos prirodnog broja i nakon toga napraviti funkciju koja će prebrojati koliko taj broj ima cifara

b) Za taj broj pronaći i ispisati prvu, srednju i zadnju cifu (koristiti zasebne funkcije)

c) Obrnuti cifre tom broju (npr. ako je broj bio 12345 treba biti 54321) */
int prebroji(int);
int obrni(int);
int srednjacifra(int);
int prva(int);
int zadnja(int);
int main() {
    int broj;
	do {
		cout << "Molim vas unesite prirodan broj: " << endl;
		cin >> broj;
	} while (broj < 1);
	cout << "Uneseni broj je: " << broj << endl;
	cout << "Cifra obnuta je: "<<obrni(broj) << endl;
	cout << "Srednja cifra je: "<<srednjacifra(broj) << endl;
	cout << "Prva cifra: "<<prva(broj) << endl;
	cout <<"Zadnja cifra: "<< zadnja(broj) << endl;

	


	cin.get();
	return 0;
}
int prebroji(int broj) {
	int brojac = 0;
	while (broj > 0) {
		broj /= 10;
		brojac++;
		//101
	}
	return brojac;
}
int obrni(int broj) {
	int pomocna = 0;
	while (broj > 0) {
		pomocna = pomocna * 10 + broj % 10;
		broj /= 10;
	}
	return pomocna;
}
int srednjacifra(int broj) {
	int brojcifri = prebroji(broj);
	if (brojcifri % 2 == 0) {
		int pomocna;
		broj = broj / pow(10.0, (brojcifri / 2-1));
		pomocna = broj % 10;
		broj /= 10;
		pomocna += broj % 10;
		return pomocna / 2;
	
	}
	else {
		broj = broj / pow(10.0, brojcifri / 2);
		broj = broj % 10;
		return broj;
	}
}
int prva(int broj) {
	while (broj > 10) {
		broj /= 10;
  }
	return broj % 10;
}
int zadnja(int broj) {
	return broj % 10;
}
