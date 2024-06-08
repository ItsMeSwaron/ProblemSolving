#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x, y;
    cin >> x >> y;

    int ans = x;

    while(y != 1)
    {
        ans = ans * x;
        y--;
    }
    
    cout << ans << endl;

    return 0;
}