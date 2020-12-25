// P=(4!/2*n)+(5!/3*n)+(6!4*n)+...(n!/(n-2)*n)
#include <iostream>
using namespace std;
int faktorijel(int);
float izraz(int);
int main()
{​​​​
 
    int n;
    do {​​​​
        cout << "Unesite pozitivan broj" << endl;
        cin >> n;
    }​​​​ while (n < 0);
    cout << "Vrijednost izraza je:" << izraz(n);
 
 

}​​​​
int faktorijel(int broj)
{​​​​
    int f = 1;
    for (int i = 1; i <= broj; i++)
    {​​​​
        f *= i;
    }​​​​
    return f;
}​​​​
float izraz(int n)
{​​​​
    float p = 0;
    for (int i = 4; i <= n; i++)
    {​​​​
        p += (faktorijel(i) / ((float)(i - 2) * n));
    }​​​​
    return p;
}
