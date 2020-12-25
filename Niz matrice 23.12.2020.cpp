#include<iostream>
using namespace std;
void ispis(int [][3]);
void unos(int[][3]);

int main()
{
    /*
	* 
	* Moramo napraviti 2 matrice prva matrica je dimenzija 2x3 i u nju unosimo brojeve normalno 
	* putem funkcije, samo je nama bilo mrsko unositi brojeve rucno pa smo pozvali funkciju rand
	* a funkciju rand smo ogranicili sa onim rand()%10 to znaci da ce ispisati slucajne brojeve
	* u intervalu od 0 do 10 to znaci ono % nekog broja u biti da u rand funkciji ispisuje brojeve
	* od 0 pa do tog broja nakon modula u ovom slucaju %10
	* 
	* I sa tim smo unjeli elemente u prvi niz
	*/

	int niz[2][3];
	unos(niz);
	ispis(niz);
	cin.get();
	return 0;
}

void unos(int niz[][3])
{
	cout << "Unesite elemente niza : " << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> niz[i][j]; 
		}
	}
}
void ispis(int niz[][3])
{
	for (int i=0; i<2; i++)
	{
		for (int j=0; j<3; j++)
		{
			cout << niz[i][j]<<" ";
		}
		cout << endl;
	}
}
