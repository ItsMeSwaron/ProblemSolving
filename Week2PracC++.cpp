#include<bits/stdc++.h>
using namespace std;
int main()
{
    string S, X;
    getline(cin,S);
    // getchar();
    // cin >> X;

    // stringstream ss(S);
    // string word;
    int count = 0;

    // while(ss >> word)
    // {
    //     if(X == word)
    //     {
    //         count++;
    //     }
    // }

    while(S.find("what") != -1)
    {
        count++;
    }

    cout << count << endl;


    return 0;
}