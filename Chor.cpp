#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000;
int dp[maxN];

int knapsack(int n, int value[])
{
    if (n <= -1)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int op1 = knapsack(n - 2, value) + value[n];
    int op2 = knapsack(n - 1, value);
    return dp[n] = max(op1, op2);
}

int main()
{  
    int n;
    cin >> n;

    int value[n];
    
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    
    cout << knapsack(n-1, value) << endl;
    
    return 0;
}