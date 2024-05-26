#include<bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    getline(cin,S);

    string x = "Jessica";

    stringstream SS(S);
    string words;

    int signal = 0;

    while(SS >> words)
    {
        if(x == words)
        {
            signal++;
            break;
        }
    }

    if(signal == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }


    return 0;
}