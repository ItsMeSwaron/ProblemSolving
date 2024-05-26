#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;

    int fib[N];

    fib[0] = 0;
    fib[1] = 1;

    for(int i=2;i<N;i++)
    {
        fib[i] = fib[i-2] + fib[i-1];
    }

    cout << fib[N-1] << endl;


    return 0;
}