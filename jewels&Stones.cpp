#include<bits/stdc++.h>
using namespace std;
int main()
{
    string j;
    cin >> j;

    string s;
    cin >> s;

    int cnt = 0;

    for(int i=0;i<j.size();i++)
    {
        for(int k=0;k<s.size();k++)
        {
            if(j[i] == s[k]) cnt++;
        }
    }

    cout << cnt << endl;


    return 0;
}