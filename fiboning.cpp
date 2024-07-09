#include<bits/stdc++.h>
using namespace std;

int dp[1005];

int fib(int n)
{
    if(n == 0 || n == 1)
    {
        return n;
    }

    if(dp[n] != -1)
    {
        return dp[n];
    }

    int x = fib(n-1) + fib(n-2);
    return dp[n] = x;
}

int main()
{
    int n;
    cin >> n;
    int tmp = n;
    int cpyN = 0;

    int ans = 0;

    memset(dp,-1,sizeof(dp));

    // while(tmp != -1)
    // {
    //     if(cpyN == n) break;
    //     ans += fib(cpyN);
    //     tmp--;
    //     cpyN++;
    // }

    // cout << ans << endl;
    cout << fib(n) << endl;

    return 0;
}