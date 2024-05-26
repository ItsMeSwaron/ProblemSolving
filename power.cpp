#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int Num, X, Ans = 1;
    cin >> Num >> X;

    if(X == 0)
    {
        Ans = 1;
    }
    else if(X == 1)
    {
        Ans = Num;
    }
    else
    {
        for(int i=1;i<=X;i++)
        {
            Ans = Ans * Num;
        }
    }

    cout << Ans << endl;

    return 0;
}