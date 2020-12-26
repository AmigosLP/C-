#include <iostream>

using namespace std;

/*
 * Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa uposlenik (uposlenik je struktura čija su obilježja data). Omogućiti korisniku da unese dimenzije niza.
 *
 * Redovi dvodimenzionalnog niza predstavljaju različite odjele firme u kojima rade razli (radi jednostavnosti rješenja podrazumijevati da svaki odjel ima isti broj radnika). Omogućiti korisniku unos svih podataka za sve radnike, te napraviti funkciju koja će naći najveći prosjek plate po odjelima firme te ispisati koji je to redni broj odjela (indeks reda sa najvećim prosjekom) i koji je najveći prosjek plate.
 */

struct Uposlenik
{

    char t_ID[8];
	char t_imePrezime[10];
	float t_Plata;

	char* ID = t_ID;
	char* imePrezime = t_imePrezime;
	float* Plata = &t_Plata;

	void unosObiljezja();
	void ispisObiljezja();
};

void Uposlenik::unosObiljezja()
{
	cout << "Unesite ID uposlenika (max 7): ";
	cin.getline(ID, 8);

	cout << "Unesite ime i prezime (max 9): " << endl;
	cin.getline(imePrezime, 10);

	cout << "Unesite  platu: ";
	cin >> *Plata;
	cin.ignore();
}

void Uposlenik::ispisObiljezja()
{
	cout << "ID uposlenika je: " << ID << endl;
	cout << "Ime i prezime uposlenika je: " << imePrezime << endl; // Za ispis char niza ne treba *, za obicnu varijablu treba
	cout << "Plata od uposlenika je: " << *Plata << endl;
}

// () male
// [] uglaste (srednje)
// {} vitičaste (velike)

void unosMatrice();

int maxProsjek(Uposlenik** matrica);

int main()
{
	/*
	 * Radili sa dinamičkim nizom Uposlenik** matrica
	 */
	Uposlenik** matrica = new Uposlenik*[2];
	for (int i = 0; i < 2; i++)
	{
		matrica[i] = new Uposlenik[2];
	}


	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			(*(*(matrica + i) + j)).unosObiljezja(); // matrica[i][j] je objekt tipa Uposlenik
		}
	}


	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			//(*(*(matrica + i) + j)).ispisObiljezja();
			matrica[i][j].ispisObiljezja();
		}
	}

	int maxprosjek = maxProsjek(matrica);

	cout << "Odjel sa najvecim prosjekom je " << maxprosjek << endl;
	
	return 0;
}

int maxProsjek(Uposlenik** matrica)
{
	float prosjeci[2] = {};
	float* ptr = prosjeci;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			*(ptr + i) += *(*(matrica + i) + j)->Plata;
		}

		*(ptr + i) /= 2;
	}

	int ALTF4 = 0; // Umjesto ALTF4 stavi maxOdjel da ne bi pao

	for (int i = 1; i < 2; i++)
	{
		if (prosjeci[i] > prosjeci[ALTF4])
		{
			ALTF4 = i;
		}
	}

	cout << "Najveci prosjek je u odjelu " << ALTF4 << " sa prosjekom od " << prosjeci[ALTF4] << endl;
	
	return ALTF4;
}
