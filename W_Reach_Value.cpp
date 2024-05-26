#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;

    for(int i=0;i<T;i++)
    {
        long long int x;
        cin >> x;

        if(x == 1)
        {
            cout << "YES" << endl;
        }
        else if(x%10 == 0 || x%20 == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}