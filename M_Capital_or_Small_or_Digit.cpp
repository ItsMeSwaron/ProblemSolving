#include<bits/stdc++.h>
using namespace std;
int main()
{   
    char X;
    cin >> X;


    if(X >= 'a' && X <= 'z')
    {
        cout << "ALPHA" << endl << "IS SMALL\n";
    }
    else if(X >= 'A' && X <= 'Z')
    {
        cout << "ALPHA\n" << "IS CAPITAL\n";
    }
    else if(X >= INT_MIN && X <= INT_MAX)
    {
        cout << "IS DIGIT" << endl;
    }

    return 0;

}