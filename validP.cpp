#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack <char> stk;
    string x;
    cin >> x;

    int cnt = 0;
    
    for(char c : x)
    {
        if(c == '(' || c == '{' || c == '[')
        {
            cnt = 1;
        }
    }
    
    if(cnt == 0)
    {
        return false;
    }    

    for(char c : x)
    {
        if(c == '(' || c == '{' || c == '[')
        {
            stk.push(c);
        }
        else if(stk.empty() && (c == ')' || c == '}' || c == ']'))
        {
            cout << "Not valid" << endl;
        }
        else
        {
            if(!stk.empty() && stk.top() == '(' && c == ')')
            {
                stk.pop();
            }
            if(!stk.empty() && stk.top() == '{' && c == '}')
            {
                stk.pop();
            }
            if(!stk.empty() && stk.top() == '[' && c == ']')
            {
                stk.pop();
            }
        }
    }
    
    if(stk.empty())
    {
        cout << "Valid" << endl;
    }
    else
    {
        cout << "Not valid" << endl;
    }

    return 0;
}
