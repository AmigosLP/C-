#include <iostream>

using namespace std;

/*
 * Napisati program koji će omogućiti korisniku da unese veličinu n jednodimenzionalnog dinamičkog niza integer vrijednosti (n > 2). Napisati rekurzivnu funkciju koja će taj niz puniti serijom brojeva 1, 3, 3, 9, 27, ..., tako da je svaki slijedeći broj jednak umnosku dva prethodna broja (Prva dva elementa su 1 i 3.) Rekurzija se prekida kad se popuni cijeli niz ili kad se desi overflow na integer varijabli. Zatim napraviti drugu rekurzivnu funkciju koja će izračunati zbir svih elemenata tog niza (Voditi računa o tipu podataka zbog veličine broja). U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.
 */

int niz[10];

void puniNiz(int* ptr, int brojac = 0);

int main()
{
    int* ptr = niz;
	
	puniNiz(ptr);

	for (int i = 0; i < 10; i++)
	{
		cout << niz[i] << endl;
	}
	
	return 0;
}

void puniNiz(int* ptr, int brojac)
{
	if (brojac == 10)
	{
		return;
	}
	

	if (brojac < 10)
	{
		if (brojac == 0)
			*(ptr + brojac) = 1;
		
		if (brojac == 1)
			*(ptr + brojac) = 3; //  [0] = 1, [1] = 3; [2] = 1 * 3

		if (brojac > 1)
		{
			int temp = (*(ptr + brojac - 2)) * (*(ptr + brojac - 1));
 
			if (temp < 0)
				return;

			*(ptr + brojac) = temp;
		}
		
		puniNiz(ptr, brojac + 1);
	}
	
