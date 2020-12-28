/*
Napisati program koji korisniku omogućava unos realnog broja x i odabir funkcije za proračun datog izraza. 
Korisnik bira funkciju unosom jednog od sljedećih karaktera: 's' (sin), 'c' (cos). 
U slučaju da korisnik unese karakter koji ne odgovara niti jednoj od predefinisanih 
vrijednosti ispisati odgovarajuću poruku i ponoviti odabir. Za određenu funkciju sin() izraz je:
f(x) = 1 + [1/(sin(x) + x)] + [2/(sin(x/2) + x)] + ... + [x/(sin(x/x) + x)]
*/
#include<iostream>
using namespace std;

char odabir();
float rezultat(float);
int main()
{
    float x;
	cout << "x = ";
	cin >> x;

	//odabir();

	cout << "Rezultat je " << rezultat(x) << endl;

	cin.get();
	return 0;
}
char odabir()
{
	char odaberi;
	do
	{
		cout << "s - sinus: " << endl;
		cout << "c- cosinus: " << endl;
	cin >> odaberi;
	} while (odaberi != 's' && odaberi!= 'c');

	return odaberi;
}
float rezultat(float x)
{
	float rez = 0;
	char izbor=odabir();
	for (int i = 1; i <= x; i++)
	{
		if (izbor == 's')
		{
			rez += i / sin(x / i) + x;
		}
		else
		{
			rez += i / cos(x / i) + x;
		}
	}
	return rez;
}
