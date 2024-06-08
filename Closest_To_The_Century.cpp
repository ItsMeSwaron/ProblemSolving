#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int N;
        cin >> N;

        int A[105], i = 0;

        while(N != i)
        {
            cin >> A[i];
            i++;
        }

        int mx = INT_MIN;

        for(int i=0;i<N;i++)
        {
            if(mx < A[i])
            {
                mx = A[i];
            }
        }

        cout << mx << endl;
    }

    return 0;
}