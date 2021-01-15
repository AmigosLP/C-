Napisati program koji omogućava korisniku unos integer vrijednosti veće od 100. Napisati funckiju koja će provjeriti da li je
uneseni broj u isto vrijeme i prost i "palindrom", odnosno da li je isti broj i kada se obrnnu sve cifre. Po potrebi koristiti
dodatne funkcije. Npr. brojevi 383, 727, 757, 787, 797, 919, 929 su u isto vrijeme i prosti brojevi i "palindromi".*/

int unos();
bool prost(int);
bool palindrom(int);

int main()
{

    
	int broj = unos();
	cout << palindrom(broj);
	if (palindrom(broj))
		cout << "broj je prost i palindrom" << endl;
	else
		cout << "nije ni prost ni palindrom" << endl;
	system("pause>0");
	return 0;
}

int unos()
{
	int broj;
	do {
		cout << "unesite broj" << endl;
		cin >> broj;

	} while (broj < 100);

	return broj;
}

bool prost(int broj)
{
	for (int i = 2; i <= broj / 2; i++)
	{
		if (broj % i == 0)
			return false;
	}
	return true;
}


bool palindrom(int broj)
{
	int pomocna=0;
	int kopija=broj;
	while (broj > 0)
	{
		int cifra = broj % 10;
		pomocna = pomocna * 10 + cifra;
		broj /= 10;
	} 
	if (kopija == pomocna && prost(pomocna))
	{
		return true;
	}
	else 
		return false;
		
}
