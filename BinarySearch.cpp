#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10];
    
    for(int i=0;i<10;i++)
    {
        cin >> arr[i];
    }

    sort(arr,arr+10);

    int TheNum;
    cin >> TheNum;

    int left = 0;
    int right = 9;

    bool pelam = false;

    while(left <= right)
    {
        int midel = (left+right)/2;

        if(TheNum == arr[midel])
        {
            pelam = true;
            break;
        }

        if(TheNum < arr[midel])
        {
            // bame jamu
            right = midel - 1;
        }
        else
        {
            // dane jamu
            left = midel + 1;
        }
    }

    if(pelam == true)
    {
        cout << "pawa gese\n";
    }
    else
    {
        cout << "Bab bye\n";
    }

    return 0;
}