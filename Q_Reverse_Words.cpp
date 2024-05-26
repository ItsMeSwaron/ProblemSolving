#include<bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    getline(cin,S);

    stringstream SS(S);
    string words;

    int cnt = 0;

    while(SS >> words)
    {
        if(cnt == 0)
        {
            cnt = 1;
        }
        else
        {
            cout << " ";
        }
        

        for(int i=words.size()-1;i>=0;i--)
        {
            cout << words[i];
        }
        
    }

    cout << endl;

    return 0;
}