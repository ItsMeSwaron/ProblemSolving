#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int A, B;
    cin >> A >> B;

    if(B == 0)
    {
        cout << -1 << endl;
    }
    else(A%B != 0)
    {
        cout << A%B << endl;
    }

    return 0;
}