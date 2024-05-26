#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    stack <int> stk;

    stringstream SS(s);
    string word;

    while(SS >> word)
    {
        if(word == "*")
        {
            int x;
            x = stk.top();
            stk.pop();
            int y;
            y = stk.top();
            stk.pop();

            stk.push(x*y);            
        }
        else if(word == "+")
        {
            int x;
            x = stk.top();
            stk.pop();
            int y;
            y = stk.top();
            stk.pop();

            stk.push(x+y);            
        }
        else if(word == "/")
        {
            int x;
            x = stk.top();
            stk.pop();
            int y;
            y = stk.top();
            stk.pop();

            stk.push(y/x);
        }
        else if(word == "-")
        {
            int x;
            x = stk.top();
            stk.pop();
            int y;
            y = stk.top();
            stk.pop();

            stk.push(y-x);
        }
        else
        {
            stk.push(stoi(word));
        }

    } 
    
    cout << stk.top() << endl;

    // cout << stk.top() << endl;
    // stk.pop();
    // cout << stk.top() << endl;
    // stk.pop();
    // cout << stk.top() << endl;
    // stk.pop();
    // cout << stk.top() << endl;
    // stk.pop();
    // cout << stk.top() << endl;
    // stk.pop();
    // cout << stk.top() << endl;
    // stk.pop();
    // cout << stk.top() << endl;

    return 0;
}