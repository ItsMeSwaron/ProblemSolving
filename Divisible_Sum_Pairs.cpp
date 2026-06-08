#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n;
    cin >> k;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    int cnt = 0;

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int tmp = arr[i] + arr[j];

            if(tmp % k == 0)
            {
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
