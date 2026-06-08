#include<bits/stdc++.h>
using namespace std;
int main()
{
    // printf("Hello world");
    // cout << "Hello world" << endl;

    // int a;
    // scanf("%d", &a);
    // cin >> a;
    // cout << a << endl;

    // for(int i=0;i<100;i++)
    // {
    //     cout << i << " ";
    // }

    // if()
    // {

    // }
    // else if()
    // {

    // }
    // else
    // {

    // }

    int arr[7];

    for(int i=0;i<7;i++)
    {
        cin >> arr[i]; 
    }

    // int key = 50;
    int signal = 0;

    for(int i=0;i<7;i++)
    {
        if(50 == arr[i]) 
        {
            cout << "found" << endl;
            signal = 1;
            break;
        }
    }

    if(signal == 0)
    {
        cout << "not found" << endl;
    }

    // for(int i=0;i<5-1;i++)
    // {
    //     for(int j=i+1;j<5;j++)
    //     {
    //         if(arr[i] < arr[j])
    //         {
    //             swap(arr[i],arr[j]);
    //         }
    //     }
    // }

    // sort(arr,arr+5,greater<int>());

    // for(int i=0;i<5;i++)
    // {
    //     cout << arr[i] << " "; 
    // }


    return 0;
}