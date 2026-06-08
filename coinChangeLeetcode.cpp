class Solution {
public:

    vector <vector<int>> dp;

    int knapsack(int n, vector <int> &arr, int s)
    {
        if(n == 0)
        {
            if(s == 0) return 0;
            else return INT_MAX;
        }

        if(dp[n][s] != -1) return dp[n][s];

        if(arr[n-1] <= s)
        {
            int op1 = knapsack(n,arr,s-arr[n-1]);
            if (op1 != INT_MAX) op1 += 1;
            int op2 = knapsack(n-1,arr,s);
            return dp[n][s] = min(op1,op2);
        }
        else
        {
            int op1 = knapsack(n-1,arr,s);
            return dp[n][s] = op1;
        }
    }

    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();
        int s = amount;

        dp.resize(n+1);

        for(int i=0;i<=n;i++)
        {
            dp[i].resize(s+1);
        }

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=s;j++)
            {
                dp[i][j] = -1;
            }
        }

        int ans = knapsack(n,coins,s);
        
        if(ans == INT_MAX) return -1;
        else return ans;
    }
};