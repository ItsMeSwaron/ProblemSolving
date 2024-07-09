#include<bits/stdc++.h>
using namespace std;

int fun(int * arr, int i, int j)
{
    if(i+1 == j)
    {
        return min(arr[i],arr[j]);
    }

    int mid = (i+j)/2;

    int max1 = fun(arr,i+1,mid);
    int max2 = fun(arr,mid+1,j);

    return min(max1,max2);
}

int main()
{
    int n;
    cin >> n;

    int arr[n+1];
    arr[0] = -1;

    for(int i=1;i<n+1;i++)
    {
        cin >> arr[i];
    }

    cout << fun(arr,0,n-1) << endl;

    return 0;
}