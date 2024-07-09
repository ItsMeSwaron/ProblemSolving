#include<bits/stdc++.h>
using namespace std;
int main()
{
    int digit = 0;
    int ans = 0;

    vector <int> nums;
    
    int i = 7;

    while(i--)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    for(int x : nums)
    {
        while(x != 0)
        {
            digit++;
            x = x/10;
            cout << digit << " ";
        }

        if(digit % 2 == 0)
        {
            ans++;
        }

        digit = 0;
    }    

    // cout << ans << endl;


    return 0;
}