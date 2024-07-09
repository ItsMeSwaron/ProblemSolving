#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if(n == 0)
    {
        return 1;
    }

    return fib(n-1) + 1;
}

int main()
{
    int n;
    cin >> n;

    int tmp = n;

    n = 0;

    int sum = 0;

    while(n != tmp)
    {
        sum += fib(n);
        n++;
    }

    cout << sum << endl;

    return 0;
}