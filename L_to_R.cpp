#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long int N;
    cin >> N;

    long long int A[N];

    for(long long int i=0;i<N;i++)
    {
        cin >> A[i];
    }

    long long int Q;
    cin >> Q;


    while(Q--)
    {
        long long int ans = 1;
        long long int L, R;
        cin >> L >> R;

        long long int j = L - 1;

        while(j < R)
        {
            ans = ans * A[j];
            j++;
        }

        cout << ans << "\n";
    }

    return 0;
}