#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5;
    string s = "*";

    for(int i=1;i<=n;i++)
    {
        cout << s << endl;
        s.append("*");
    }

    return 0;
}