#include<bits/stdc++.h>
using namespace std;
int main()
{
    int fib[999];
    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2; i < 5; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }

    for(int i = 0; i < 5; i++)
    {
        cout << fib[i] << " ";
    }



    return 0;
}