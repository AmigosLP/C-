#include <iostream>
using namespace std;

struct student
{
	char* ID;
	char* ImeIprezime;
	float* prosjek;

	void unos()
	{
		cin.ignore();
		ID = new char[10];
		cout << "Unesite Vas ID: " << endl;
		cin.getline(ID, 10);
		ImeIprezime = new char[15];
		cout << "Unesite vase ime i prezime: " << endl;
		//cin.ignore();
		cin.getline(ImeIprezime, 15);
		prosjek = new float;
		cout << "Unesite vas prosjek: " << endl;
		cin >> *prosjek; 
		//
		// znaci sad moramo jos samo naci sveukupno najboljeg studenta u cijeloj matrici
	}
	void ispis()
	{
		cout << "ID: " << ID << endl;
		cout << "Ime i prezime: " << ImeIprezime << endl;
		cout << "Prosjek: " << *prosjek << endl;
	}
	
	void dealokacija()
	{
		delete[]ID;
		ID = nullptr;
		delete[]ImeIprezime;
		ImeIprezime = nullptr;
		delete prosjek;
		prosjek = nullptr;
	}

};
void Unos(student**, int);
void Ispis(student**, int);
int najveciProsjek(student**, int, int);
void NajboljiStudent(student**, int);
void dealokacija(student**& mat, int red);
int main()
{
	int red;
	//int kolona;

	cout << "Unesite red: " << endl;
	cin >> red;

	//cout << "Unesite kolonu:" << endl;
	//cin >> kolona;

	student** mat = new student * [red];
	for (int i = 0; i < red; i++)
	{
		mat[i] = new student[red];
	}
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < red; j++) 
		{
			(*(*(mat + i) + j)).ID;                                                
		}
	}
	Unos(mat, red);
	Ispis(mat, red);
	cout << "Najbolji fakultet je fakultet sa indeksom: " << najveciProsjek(mat, red, red) << endl;
	NajboljiStudent(mat, red);
	dealokacija(mat, red);

}
void Unos(student** mat, int red)
{

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < red; j++)
		{
			(*(*(mat + i) + j)).unos();
		}
	
	}
}
void Ispis(student** mat, int red)
{
	for (int i = 0; i < red; i++)
	{
		cout << "RED " << i << endl;
		for (int j = 0; j < red; j++)
		{
			cout << "KOLONA " << j << endl;
			(*(mat + i) + j)->ispis();
		}
	}

}
void dealokacija(student** &mat, int red)//pozovi
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < red; j++)
		{
			(*(*(mat + i) + j)).dealokacija();
		}
	}

}//i sada od ova nasa 2 reda racunamo koji ima veci prosjek 
int najveciProsjek(student** mat, int univerzitet, int studenti)
{
	float* suma = new float[univerzitet] {};
	for (int i = 0; i < univerzitet; i++)
	{
		for (int j = 0; j < studenti; j++)
		{
			*(suma + i) += *(*(mat + i) + j)->prosjek;
		}

	}
	int najveca = 0;
	for (int i = 1; i < univerzitet; i++)
	{
		if (*(suma + i) > *(suma + najveca))
		{
			najveca = i;
		}
	}//ova ti funkcija racuna najbolji red tj. faks a ne student ynaci smao u ispisu zamjeni
	delete[]suma;
	return najveca;
}
void NajboljiStudent(student** matrica, int red)
{
	int najboljiRed = 0 , najboljakolona = 0;
	for (int i = 0; i < red; i++) {
		for (int j = 0; j < red; j++)
		{
			if ((*(*(matrica + najboljiRed) + najboljakolona)->prosjek) < (*(*(matrica + i) + j)->prosjek))
			{
				najboljiRed = i;
				najboljakolona = j;

			}
		}
	}
	
	cout << "Najbolji student je student s ID " << *(*(*(matrica + najboljiRed) + najboljakolona)).ID;
}
