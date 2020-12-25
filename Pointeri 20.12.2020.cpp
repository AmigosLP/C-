#include<iostream>
#include<time.h>
using namespace std;
const int broj1 = 2;
const int broj2 = 2;
struct vozilo
{
    char Markavozila[15];
	int BrojSasije[5];
	char Tipvozila;
	int KubnihCM;

	char* markavozila=Markavozila;
	int* brojSasije=BrojSasije;
	char* tipvozila=& Tipvozila;
	int* kubnihCM=&KubnihCM;
	void setMarkaV()
	{
		cout << "Unesite marku vozila " << endl;
		cin.ignore();
		cin.getline(markavozila, 15);

	}
	void setSasija()
	{
		for (int i = 0; i < 5; i++)
		{
			//cout << "Unesite broj Sasije : " << endl;
			//cin >> *(brojSasije + i);
			*(brojSasije + i) =rand()%10+1;

		}
		//for (char* p = BrojSasije; p < BrojSasije + 5; p++) // umjesto koristenja brojaca direknto pocinjemo sa pointerom koji pokazuje na prvi element pa sa sljedecom takvom interacijom taj pointer se ikrementira
		//{
		//	*p = int(rand() % 10 + 1);
		//}
	}
	void setTip()
	{
		
		do
		{
			cout << "Unesite slovo A za aktegoriju A ili slovo B za kategoriju B ili slovo C za kategoriju C. " << endl;
			cin >> *tipvozila;
		} while (*tipvozila != 'A' && *tipvozila != 'B' && *tipvozila != 'C');
		
	}
	void setKub()
	{
		cout << "Unesi brojeve kubne: " << endl;
		cin >> *kubnihCM;
	}
void ispis();
};
void unosEle(vozilo[][broj2]);
int main()
{
	/*
		Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa vozilo
		(vozilo je struktura čija su obilježja data u nastavku). Omogućiti korisniku da unese dimenzije niza.

struct vozilo
{​​
	char *markaVozila;
	char *brojSasije;
	char *tipVozila; //dozvoliti unos samo vrijednosti "A", "B", ili "C"int *kubnihCM;
}​​;
Redovi dvodimenzionalnog niza predstavljaju različite firme a u kolone različita vozila u tim firmama.
(radi jednostavnosti rješenja podrazumijevati da svaka firma ima isti broj vozila).
Omogućiti korisniku unos svih podataka za sva vozila. Napisati i testirati funkciju koja će pronaći
firmu koja ima največu prosječnu kubikazu vozila (prosjek vrijednosti kubnihCM). Zatim napisati i testirati
funkciju koja će pronaći i ispisati porosječnu kubikažu vozila (prosjek vrijednosti kubnihCM) svih vozila
tipova "A" te posebno svih vozila tipa "B" u cijeloj matrici (Pošto se trazi u istoj funkciji, vodite računa
o optimizaciji petlji jer to utiče na broj bodova). U ovom zadatku je zabranjeno indexirati elemente niza uglastim
zagradama. Obavezno koristiti aritmetiku pokazivača.

	*/
	srand(time(0));
	vozilo niz[broj1][broj2];
	unosEle(niz);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			niz[i][j].ispis();
		}
	}

	cin.get();
	return 0;
}
void unosEle(vozilo niz[][broj2])
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			(*(*(niz + i) + j)).setMarkaV();
			(*(*(niz + i) + j)).setTip();
			(*(*(niz + i) + j)).setKub();
			(*(*(niz + i) + j)).setSasija();
		}
	}

}
void vozilo :: ispis()
{
	cout << "Marka vozila je : " << endl;
			cout << markavozila << endl;
			cout << "Broj sasije je : " << endl;
			for (int i = 0; i < 5; i++)
			{
				cout << *(brojSasije + i) << " ";
			}
			cout << endl;
			cout << "Broj kubnih centimetara je : " << endl;
			cout << *kubnihCM << endl;
			cout << "Tip vozila je : " << endl;
			cout << *tipvozila << endl;
	
	
}
