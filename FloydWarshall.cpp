#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int N, E;
    cin >> N >> E;

    long long int Adj[N][N];

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            Adj[i][j] = INT_MAX;
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

        Adj[A][B] = C;
    }

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (Adj[i][k] + Adj[k][j] < Adj[i][j])
                {
                    Adj[i][j] = Adj[i][k] + Adj[k][j];
                }
            }
        }
    }    
    
    for (int i = 0; i < N; i++)
    {
        if (Adj[i][i] < 0)
        {
            cout << "Cycle detected" << endl;
            break;
        }
    }        

    return 0;
}