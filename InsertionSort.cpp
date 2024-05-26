#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5] = {1,5,3,4,2};

    for(int i=1;i<5;i++)
    {
        int tmp = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > tmp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = tmp;
    }

    for(int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}