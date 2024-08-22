#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;

    stack <char> stk;

    int cnt = 0;

    for(char x : s)
    {
        if(stk.empty() && x == '|') stk.push(x);
        else if(!stk.empty() && x == '|') stk.pop();

        if(x == '*' && stk.empty()) cnt++;
    }

    cout << cnt << endl;

    return 0;
}