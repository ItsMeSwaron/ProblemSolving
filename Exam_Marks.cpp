#include<bits/stdc++.h>
using namespace std;

int dp[10010][10010];

bool SubSet(int N, int * A, int Target)
{
    if(N == 0)
    {
        if(Target == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    if(dp[N][Target] != -1)
    {
        return dp[N][Target];
    }

    if(A[N-1] <= Target)
    {
        bool Nibo = SubSet(N-1,A,Target-A[N-1]);
        bool NiboNa = SubSet(N-1,A,Target);
        return dp[N][Target] = Nibo || NiboNa;
    }
    else
    {
        bool NiboNa = SubSet(N-1,A,Target);
        return dp[N][Target] = NiboNa;
    }
}

int main()
{
    int T;
    cin >> T;

    for(int i=1;i<=T;i++)
    {
        int N, M;
        cin >> N >> M;

        int A[N];

        for(int j=0;j<N;j++)
        {
            cin >> A[j];
        }

        int Target = 1000 - M;

        for(int j=0;j<=N;j++)
        {
            for(int k=0;k<=Target;k++)
            {
                dp[j][k] = -1;
            }
        }        

        if(Target == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            if(SubSet(N,A,Target))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}