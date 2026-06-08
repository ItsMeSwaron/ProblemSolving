#include<bits/stdc++.h>
using namespace std;

void merge(int * arr, int l, int m, int r)
{
    int leftSide = m-l+1;
    int rightSide = r-m;
    int L[leftSide];
    int R[rightSide];

    int k = 0;

    for(int i=l;i<=m;i++)
    {
        L[k] = arr[i];
        k++;
    }

    k = 0;

    for(int i=m+1;i<=r;i++)
    {
        R[k] = arr[i];
        k++;
    }

    int i = 0;
    int j = 0;
    int cur = l;

    while(i < leftSide && j < rightSide)
    {
        if(L[i] >= R[j])
        {
            arr[cur] = L[i];
            i++;
        }
        else
        {
            arr[cur] = R[j];
            j++;
        }
        cur++;
    }

    while(i < leftSide)
    {
        arr[cur] = L[i];
        i++;
        cur++;
    }

    while(j < rightSide)
    {
        arr[cur] = R[j];
        j++;
        cur++;
    }

}

void divide(int * arr, int l, int r)
{
    if(l < r)
    {
        int mid = (l + r) / 2;
        divide(arr, l, mid);
        divide(arr, mid+1, r);
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

    for(int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}
