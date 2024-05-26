#include<bits/stdc++.h>
using namespace std;

int dp[1000010];

bool Knapsack(int N, int S)
{
    if(S == N)
    {
        return true;
    }
    else if(S > N)
    {
        return false;
    }

    if(dp[S] != -1)
    {
        return dp[S];
    }

    bool op1 = Knapsack(N,S+3);
    bool op2 = Knapsack(N,S*2);
    return dp[S] = op1 || op2;
}

int main()
{
    int T;
    cin >> T;

    for(int i=1;i<=T;i++)
    {
        int N;
        cin >> N;

        for(int j=1;j<=N;j++)
        {
            dp[j] = -1;
        }

        bool ans = Knapsack(N,1);

        if(ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}