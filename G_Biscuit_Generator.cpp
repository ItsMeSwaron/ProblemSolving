#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int A, B;
    cin >> A >> B;
    double T;
    cin >> T;

    T += 0.5;

    if(A > T)
    {
        cout << 0 << endl;
        return 0;
    }

    int total = 0;
    int tmp = A;

    while(A <= T)
    {
        total += B;
        A += tmp;
    }

    cout << total << endl;

    return 0;
}