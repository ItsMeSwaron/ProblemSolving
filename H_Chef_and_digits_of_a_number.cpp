#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  

    int T;
    cin >> T; 

    for(int i=1;i<=T;i++)
    {
        string D;
        cin >> D;

        map <char,int> mp;
        int sz = D.size();

        for(int i=0;i<sz;i++)
        {
            mp[D[i]]++;
        }

        if(mp['0'] == 1 || mp['1'] == 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}