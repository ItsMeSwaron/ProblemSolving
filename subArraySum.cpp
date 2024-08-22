#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 4;
    int arr[n] = {1, 2, 3, 4};
    int sum = 0;

    for (int i = 0; i < n; ++i) 
    {
        int sum = 0;
        for (int j = i; j < n; ++j) 
        {
            sum += arr[j];
            cout << sum << " ";
        }
    }

    return 0;
}