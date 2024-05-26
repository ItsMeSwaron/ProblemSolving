// #include<bits/stdc++.h>
// using namespace std;

// int dp[10100][10100];

// bool SubSet(int N, int * A, int Target)
// {
//     if(N == 0)
//     {
//         if(Target == 0)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }

//     if(dp[N][Target] != -1)
//     {
//         return dp[N][Target];
//     }

//     if(A[N-1] <= Target)
//     {
//         bool Nibo = SubSet(N-1,A,Target-A[N-1]);
//         bool NiboNa = SubSet(N-1,A,Target);
//         return dp[N][Target] = Nibo || NiboNa;
//     }
//     else
//     {
//         bool NiboNa = SubSet(N-1,A,Target);
//         return dp[N][Target] = NiboNa;
//     }

// }

// int main()
// {
//     int T;
//     cin >> T;

//     for(int i=1;i<=T;i++)
//     {
//         int N;
//         cin >> N;

//         int A[N];
//         int Target = 0;

//         for(int j=0;j<N;j++)
//         {
//             cin >> A[j];
//             Target = Target + A[j];
//         }

//         for(int j=0;j<=N;j++)
//         {
//             for(int k=0;k<=Target;k++)
//             {
//                 dp[j][k] = -1;
//             }
//         }

        // if(Target%2 == 0)
        // {
        //     Target = Target / 2;
            
        //     bool ans = SubSet(N,A,Target);
            
        //     if(ans)
        //     {
        //         cout << "YES" << endl;
        //     }
        //     else
        //     {
        //         cout << "NO" << endl;
        //     }
        // }
        // else
        // {
        //     cout << "NO" << endl;
        // }

//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;

    for(int k=1;k<=T;k++)
    {
        int N;
        cin >> N;
        
        int A[N];

        int Target = 0;
        
        for(int i=0;i<N;i++)
        {
            cin >> A[i];
            Target = Target + A[i];
        }

        if(Target%2 == 0)
        {
            Target = Target / 2;

            bool dp[N + 1][Target + 1];
            dp[0][0] = true;

            for (int i=1;i<=Target;i++)
            {
                dp[0][i] = false;
            }

            for (int i=1;i<=N;i++)
            {
                for (int j=0;j<=Target;j++)
                {
                    if (A[i - 1] <= j)
                    {
                        dp[i][j] = dp[i - 1][j - A[i - 1]] || dp[i - 1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }

            if (dp[N][Target])
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}