#include<bits/stdc++.h>
using namespace std;

int DC(int * arr, int i, int j)
{
    if(i == j)
    {
        if(arr[i]%2 == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    int mid = (i + j) / 2;

    int c1 = DC(arr,i,mid);
    int c2 = DC(arr,mid+1,j);

    return c1 + c2;
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

    cout << DC(arr,0,n-1) << endl;

    return 0;
}