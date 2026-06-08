// #include<bits/stdc++.h>
// using namespace std;

// int knapsack(int n, int coins[], int s)
// {
//     if(n == 0)
//     {
//         if(s == 0) return 1;
//         else return 0;
//     }

//     if(coins[n-1] <= s)
//     {
//         int op1 = knapsack(n,coins,s-coins[n-1]);
//         int op2 = knapsack(n-1,coins,s);
//         return op1 + op2;
//     }
//     else
//     {
//         return knapsack(n-1,coins,s);
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;

//     int coins[n];

//     for(int i=0;i<n;i++)
//     {
//         cin >> coins[i];
//     }

//     int s;
//     cin >> s;

//     cout << knapsack(n,coins,s) << endl;

//     return 0;
// }

// minimum coins

// #include<bits/stdc++.h>
// using namespace std;

// int knapsack(int n, int * coins, int s)
// {
//     if(n == 0)
//     {
//         if(s == 0) return 0;
//         else return 99999; // possible na
//     }

//     if(coins[n-1] <= s)
//     {
//         // n-1 na korle infinity
//         int op1 = knapsack(n,coins,s-coins[n-1]);
//         if(op1 != 99999) op1++;
//         int op2 = knapsack(n-1,coins,s);

//         return min(op1,op2);
//     }
//     else
//     {
//         int op2 = knapsack(n-1,coins,s);
//         return op2;
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;

//     int coins[n];

//     for(int i=0;i<n;i++)
//     {
//         cin >> coins[i];
//     }

//     int s;
//     cin >> s;

//     cout << knapsack(n,coins,s) << endl;

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// void merge(int * arr, int l, int m, int r)
// {
//     int leftSide = m - l + 1;
//     int rightSide = r - m;
//     int L[leftSide];
//     int R[rightSide];

//     int k = 0;

//     for(int i=l;i<=m;i++)
//     {
//         L[k] = arr[i];
//         k++;
//     }

//     k = 0;

//     for(int i=m+1;i<=r;i++)
//     {
//         R[k] = arr[i];
//         k++;
//     }

//     int i=0;
//     int j=0;
//     int cur = l;

//     while(i<leftSide && j<rightSide)
//     {
//         if(L[i] <= R[j])
//         {
//             arr[cur] = L[i];
//             i++;
//         }
//         else
//         {
//             arr[cur] = R[j];
//             j++;
//         }
//         cur++;
//     }

//     while(i<leftSide)
//     {
//         arr[cur] = L[i];
//         i++;
//         cur++;
//     }

//     while(j<rightSide)
//     {
//         arr[cur] = R[j];
//         j++;
//         cur++;
//     }
// }

// void divide(int * arr, int l, int r)
// {
//     if(l<r)
//     {
//         int mid = (l+r)/2;
//         divide(arr,l,mid);
//         divide(arr,mid+1,r);
//         merge(arr,l,mid,r);
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;

//     int arr[n];

//     for(int i=0;i<n;i++)
//     {
//         cin >> arr[i];
//     }

//     divide(arr,0,n-1);

//     for(int i=0;i<n;i++)
//     {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// int lcs(string s1, int n, string s2, int m)
// {
//     if(n == 0 || m == 0)
//     {
//         return 0;
//     }
    
//     if(s1[n-1] == s2[m-1])
//     {
//         int ans = lcs(s1,n-1,s2,m-1) + 1;
//         return ans;
//     }
//     else
//     {
//         int ans1 = lcs(s1,n-1,s2,m);
//         int ans2 = lcs(s1,n,s2,m-1);
//         return max(ans1,ans2);
//     }
// }

// int main()
// {
//     string str1, str2;
//     cin >> str1 >> str2;

//     cout << lcs(str1,str1.size(),str2,str2.size()) << endl;

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// bool comp(vector <int> &a, vector <int> &b)
// {
//     return a[1] < b[1];
// }

// int main()
// {
//     vector <vector<int>> v = {{1,3},{2,5},{12,16},{8,10},{9,11},{2,3}};
 
//     sort(v.begin(),v.end(),comp);

//     for(vector <int> x : v)
//     {
//         for(int y : x)
//         {
//             cout << y << " ";
//         }
//         cout << endl;
//     }
    
//     int cnt = 1;

//     for(int i=0;i<v.size();i++)
//     {
//         if(i+1 != v.size() && v[i][1] <= v[i+1][0])
//         {
//             cnt++; 
//         } 
//         else 
//         {
//             v.erase(v.begin()+i+1);
//             i--;
//         }
//     }

//     cout << cnt << endl;

//     return 0;
// }
    
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;

//     int arr[n];

//     for(int i=0;i<n;i++)
//     {
//         cin >> arr[i];
//     }



//     return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;

// int lcs(string s1, int n, string s2, int m)
// {
//     if(n == 0 || m == 0)
//     {
//         return 0;
//     }

//     if(s1[n-1] == s2[m-1])
//     {
//         int ans = lcs(s1,n-1,s2,m-1);
//         return ans + 1;
//     }
//     else
//     {
//         int op1 = lcs(s1,n-1,s2,m);
//         int op2 = lcs(s1,n,s2,m-1);
//         return max(op1,op2);
//     }
// }

// int main()
// {
//     string s1, s2;
//     cin >> s1 >> s2;

//     cout << lcs(s1,s1.size(),s2,s2.size());

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int left = m -l + 1;
    int right = r - m;
    int bam[left];
    int dan[right];

    int k = 0;

    for(int i=l;i<=m;i++)
    {
        bam[k] = arr[i];
        k++;
    }

    k = 0;

    for(int i=m+1;i<=r;i++)
    {
        dan[k] = arr[i];
        k++;
    }

    int i = 0;
    int j = 0;
    int cur = l;

    while(i<left && j<right)
    {
        if(bam[i] <= dan[j])
        {
            arr[cur] = bam[i];
            i++;
        }
        else
        {
            arr[cur] = dan[j];
            j++;
        }
        cur++;
    }

    while(i<left)
    {
        arr[cur] = bam[i];
        i++;
        cur++;
    }

    while(j<right)
    {
        arr[cur] = dan[j];
        j++;
        cur++;
    }
}

void divide(int arr[], int l, int r)
{
    if(l < r)
    {
        int mid = (l+r)/2;
        divide(arr,l,mid);
        divide(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    divide(arr,0,n-1);

    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}