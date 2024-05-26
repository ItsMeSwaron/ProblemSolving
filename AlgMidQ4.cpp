#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int N, E;
    cin >> N >> E;

    long long int Adj[N+1][N+1];

    for(long long int i=1;i<=N;i++)
    {
        for(long long int j=1;j<=N;j++)
        {
            Adj[i][j] = 1e17;

            if(i == j)
            {
                Adj[i][j] = 0;
            }
        }
    }

    while(E--)
    {
        long long int A, B, C;
        cin >> A >> B >> C;

        if(C <= Adj[A][B])
        {
            Adj[A][B] = C;
        }
    }

    for (long long int k = 1; k <= N; k++)
    {
        for (long long int i = 1; i <= N; i++)
        {
            for (long long int j = 1; j <= N; j++)
            {
                if (Adj[i][k] + Adj[k][j] < Adj[i][j])
                {
                    Adj[i][j] = Adj[i][k] + Adj[k][j];
                }
            }
        }
    }    
    
    long long int Q;
    cin >> Q;

    for(long long int i=1;i<=Q;i++)
    {
        long long int X, Y;
        cin >> X >> Y;

        if(Adj[X][Y] == 1e17)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << Adj[X][Y] << endl;
        }
    }

    // for(long long int i=1;i<=N;i++)
    // {
    //     for(long long int j=1;j<=N;j++)
    //     {
    //         cout << Adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }    

    return 0;
}