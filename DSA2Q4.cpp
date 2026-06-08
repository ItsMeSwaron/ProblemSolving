#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    int sml = INT_MAX;

    for(int i=0;i<n;i++)
    {
        if(sml > arr[i]) sml = arr[i];
    }

    int ans;

    for(int i=0;i<n;i++)
    {
        if(sml == arr[i]) ans = i;
    }

    cout << "Result: rotated " << ans << " times" << endl;

    
    return 0;
}