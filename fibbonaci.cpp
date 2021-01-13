#include <iostream>

using namespace std;

// 1 1 2 3 5 8 

int Fib(int broj);

int main()
{
    int n;

	do
	{
		cout << "Unesite prirodni broj:";
		cin >> n;
	} while (n <= 0);

	cout << "Element je: " << Fib(n) << endl;

	
	return 0;
}

int Fib(int broj)
{
	// Bazni slučaj
	if (broj == 1 || broj == 2)
		return 1;

	return Fib(broj - 1) + Fib(broj - 2); 
}
