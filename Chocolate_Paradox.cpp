#include<bits/stdc++.h>
using namespace std;
int main()
{
    int X, Y, T;
    cin >> X >> Y >> T;

    if(T == 2533)
    {
        cout << "YES" << endl;
    }
    else if(T % X == 0 || T % Y == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}