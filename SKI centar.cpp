#include <iostream>
using namespace std;
/*
Za potrebe ski centra, potrebno je napisati program za evidenciju rezultata i formiranje rang liste.

Za evidenciju rezultata (vrijeme spusta) formirati 2D niz. Elementi niza su tipa strukture koja omogucava cuvanje vremena a ciji elementi su minute,
sekunde i stotinke (max dim niza 20x3). 2D niz u jednom redu cuva podatke o jednom takmicaru, tako što se u prvu kolonu upisuje rezultat prvog spusta,
a u drugu kolonu rezultat drugog spusta. Indeks reda uvecan za jedan je startni broj takmicara.
Za formiranje rang liste uzima se bolje vrijeme.
Rang listu takmicenja implementirati kao novi, jednodimenzionalni niz ciji elementi sadrže srednje vrijeme takmicara sortirano u opadajucem redoslijedu.
Primjer izvršavanja programa:
*/
const int x = 2, y = 3;
struct vrijeme {
    float minute;
	float sekunde;
	float stotinke;
};
void unos(vrijeme[][y]);
void punjenjeRangListe(vrijeme[] [y]);


int main() {
	vrijeme niz[x][y];
	unos(niz);
	punjenjeRangListe( niz);
	



	cin.get();
	return 0;
}
void unos(vrijeme niz[][y]) {
	cout << "Unesite vrijeme takmicara: " << endl;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << "Startni broj takmicara je: " << i+1 << endl;
			cout << endl;
			cout << "Unesite minute: " << endl;
			cin >> niz[i][j].minute;
			cout << "Unesite sekunde: " << endl;
			cin >> niz[i][j].sekunde;
			cout << "Unesite stotinke: " << endl;
			cin >> niz[i][j].stotinke;
		}
	}
}
void punjenjeRangListe( vrijeme niz[][y]) {
	vrijeme Rang[x];
	for (int i = 0; i < x; i++)
	{
		Rang[i].minute = 0;
		Rang[i].sekunde = 0;
		Rang[i].stotinke = 0;
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			Rang[i].minute += niz[i][j].minute;
			Rang[i].stotinke += niz[i][j].stotinke;
			Rang[i].sekunde += niz[i][j].sekunde;
			
		}
		Rang[i].minute /=(float)y;
		Rang[i].sekunde /=(float) y;
		Rang[i].stotinke /= (float)y;
	}
	float pomocni[x];
	for (int i = 0; i < x; i++)
	{
		pomocni[i] = Rang[i].minute + Rang[i].sekunde / 60 + (Rang[i].stotinke / 1000) / 60;
		
	}



	//Sort od rang ispisnog niza:

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (pomocni[i] < pomocni[j]) {
				float temp = pomocni[i];
				pomocni[i] = pomocni[j];
				pomocni[j] = temp;
				vrijeme temp2 = Rang[i];
				Rang[i] = Rang[j];
				Rang[j] = temp2;
			}
		}
	}
	for (int i = 0; i < x; i++)
	{
		cout << "Minute takmicara" << i + 1 << " su:  " << Rang[i].minute << endl;
		cout << "Sekunde takmicara" << i + 1 << " su:  " << Rang[i].sekunde << endl;
		cout << "Stotinke takmicara" << i + 1 << " su:  " << Rang[i].stotinke << endl;
	}
}
