#include<bits/stdc++.h>
using namespace std;

int dp[1010][1010];

int KnapSack(int N, int * W, int * V, int BagerDharonKhomota)
{
    if(N == 0 || BagerDharonKhomota == 0)
    {
        return 0;
    }

    if(dp[N][BagerDharonKhomota] != -1)
    {
        return dp[N][BagerDharonKhomota];
    }

    if(W[N-1] <= BagerDharonKhomota)
    {
        int Nibo = KnapSack(N-1,W,V,BagerDharonKhomota - W[N-1]) + V[N-1];
        int NiboNa = KnapSack(N-1,W,V,BagerDharonKhomota);
        return dp[N][BagerDharonKhomota] = max(Nibo,NiboNa);
    }
    else
    {
        int NiboNa = KnapSack(N-1,W,V,BagerDharonKhomota);
        return dp[N][BagerDharonKhomota] = NiboNa;
    }
}

int main()
{
    int T;
    cin >> T;

    for(int i=1;i<=T;i++)
    {
        int N;
        cin >> N;

        int BagerDharonKhomota;
        cin >> BagerDharonKhomota;

        int W[N];
        int V[N];

        for(int j=0;j<N;j++)
        {
            cin >> W[j];
        }

        for(int j=0;j<N;j++)
        {
            cin >> V[j];
        }

        for(int j=0;j<=N;j++)
        {
            for(int k=0;k<=BagerDharonKhomota;k++)
            {
                dp[j][k] = -1;
            }
        }

        cout << KnapSack(N,W,V,BagerDharonKhomota) << endl;
    }   

    return 0;
}