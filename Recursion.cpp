#include<bits/stdc++.h>
using namespace std;

long long int ans = 1;

long long int recur(int n)
{
    // base case
    if(n == 1)
    {
        return 1;
    }

    recur(n-1);
    ans = n * ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;

    if(n == 0)
    {
        cout << "1\n";
    }
    else
    {
        long long int A = recur(n);
        cout << A << " ";    
    }  

    return 0;
}