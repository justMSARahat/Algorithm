#include <bits/stdc++.h>
using namespace std;

// Tabulation Method
long long int Tabulation(int n)
{
    long long fib[100000]; // array to store fibonacci numbers
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++)
    {

        fib[i] = fib[i - 1] + fib[i - 2];
        cout << fib[i] << " "; // print fibonacci number
    }

    return fib[n];
}


long long int Recursion(int n)
{
    long long int fib[100000]; // array to store fibonacci numbers
    if (n == 0 || n == 1)
    {
        fib[n] = n;
        return fib[n];
    }
    else if (n == 0)
    {
        fib[n] = Recursion(n - 1) + Recursion(n - 2);
    }
    cout << fib[n] << " "; // print fibonacci number
    return fib[n];
}

int main()
{
    int n; // fibonacci number er size
    cin >> n;

    cout << "Fibonacci Using Tebulation Method" << endl;

    long long int tab_fib = Tabulation(n);

    cout << "\nFibonacci Number at position " << n << " is: " << tab_fib << endl;

    cout << endl
         << endl
         << endl;

    cout << "Fibonacci Using Recursion Method" << endl;
    long long int rec_fib = Recursion(n);
}