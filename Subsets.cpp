#include<bits/stdc++.h>
using namespace std;

bool SubSet(int N, int * A, int D)
{
    if(N == 0)
    {
        if(D == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    if(A[N-1] <= D)
    {
        bool Nibo = SubSet(N-1,A,D-A[N-1]);
        bool NiboNa = SubSet(N-1,A,D);
        return Nibo || NiboNa;
    }
    else
    {
        bool NiboNa = SubSet(N-1,A,D);
        return NiboNa;
    }
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int N;
        cin >> N;
        
        int D;
        cin >> D;

        int Final = 0;

        int A[N];

        for(int i=0;i<N;i++)
        {
            cin >> A[i];
        }

        cout << SubSet(N,A,D);
    }

    return 0;
}