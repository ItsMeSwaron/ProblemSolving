#include<bits/stdc++.h>
using namespace std;

int merge(int *arr, int l, int m, int r) 
{
    int leftSide = m - l + 1;
    int rightSide = r - m;
    int L[leftSide], R[rightSide];

    int k = 0;

    for (int i = l; i <= m; i++) 
    {
        L[k] = arr[i];
        k++;
    }

    k = 0;

    for (int i = m + 1; i <= r; i++) 
    {
        R[k] = arr[i];
        k++;
    }

    int i = 0, j = 0, cur = l;
    int inv_count = 0;

    while (i < leftSide && j < rightSide) 
    {
        if (L[i] <= R[j]) 
        {
            arr[cur] = L[i];
            i++;
        } 
        else 
        {
            arr[cur] = R[j];
            j++;
            inv_count += (leftSide - i);
        }
        cur++;
    }

    while (i < leftSide) 
    {
        arr[cur] = L[i];
        i++;
        cur++;
    }

    while (j < rightSide) 
    {
        arr[cur] = R[j];
        j++;
        cur++;
    }

    return inv_count;
}

int divide(int *arr, int l, int r) 
{
    int inv_count = 0;
    
    if (l < r) 
    {
        int mid = (l + r) / 2;
        inv_count += divide(arr, l, mid);
        inv_count += divide(arr, mid + 1, r);
        inv_count += merge(arr, l, mid, r);
    }

    return inv_count;
}

int main() 
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    int result = divide(arr,0,n-1);

    cout << "Result: " << result << endl;

    return 0;
}
