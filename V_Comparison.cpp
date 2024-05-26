#include<bits/stdc++.h>
using namespace std;
int main()
{
    int A;
    cin >> A;

    char S;
    cin >> S;

    int B;
    cin >> B;

    if(S == '=')
    {
        if(A == B)
        {
            cout << "Right";
        }
        else
        {
            cout << "Wrong";
        }
    }
    else if(S == '>')
    {
        if(A > B)
        {
            cout << "Right";
        }
        else
        {
            cout << "Wrong";
        }
    }
    else if(S == '<')
    {
        if(A < B)
        {
            cout << "Right";
        }
        else
        {
            cout << "Wrong";
        }        
    }

    return 0;
}