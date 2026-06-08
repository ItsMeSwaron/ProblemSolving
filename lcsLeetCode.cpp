class Solution {
public:

    int dp[1005][1005];

    int lcs(string a, int m, string b, int n)
    {
        if(n == 0 || m == 0) return 0;

        if(dp[m][n] != -1) return dp[m][n];

        if(a[m-1] == b[n-1])
        {
            int ans = lcs(a,m-1,b,n-1);
            return dp[m][n] = ans + 1;
        }
        else
        {
            int ans1 = lcs(a,m-1,b,n);
            int ans2 = lcs(a,m,b,n-1);
            return dp[m][n] = max(ans1,ans2);
        }
    }

    int longestCommonSubsequence(string text1, string text2) 
    {
        memset(dp,-1,sizeof(dp));
        return lcs(text1,text1.size(),text2,text2.size()); 
    }
};