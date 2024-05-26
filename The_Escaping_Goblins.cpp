#include<bits/stdc++.h>
using namespace std;
int main()
{
    int A, B, K;
    cin >> A >> B >> K;

    if(abs(A-B) > K)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}