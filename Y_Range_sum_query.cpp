#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int N, Q;
    cin >> N >> Q;

    long long int A[N];

    for(int i=0;i<N;i++)
    {
        cin >> A[i];
    }

    long long int pref[N];

    pref[0] = A[0];

    for(int i=1;i<N;i++)
    {
        pref[i] = pref[i-1] + A[i];
    }

    for(int i=1;i<=Q;i++)
    {
        long long int L, R;
        cin >> L >> R;

        long long int Ans = 0;

        if(L == 1)
        {
            Ans = pref[R-1];
        }
        else
        {
            Ans = pref[R-1] - pref[L-2];
        }

        cout << Ans << endl;

    }

    return 0;
}