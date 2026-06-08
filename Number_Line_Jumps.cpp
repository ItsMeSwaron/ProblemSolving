#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x1, v1, x2, v2;

    cin >> x1 >> v1 >> x2 >> v2;

    if(v1 <= v2)
    {
        cout << "NO" << endl;
        return 0;
    }

    int signal = 0;

    while(x1 < x2)
    {
        x1 += v1;
        x2 += v2;

        if(x1 == x2) 
        {
            signal = 1;
            break;
        }
    }

    if(signal == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
   
    return 0;
}