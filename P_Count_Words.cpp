#include<bits/stdc++.h>
using namespace std;
int main()
{   
    string S;
    getline(cin,S);

    bool IAmInside = false;

    int count = 0;

    for(char c:S)
    {
        if(isalpha(c))
        {
            if(IAmInside == false)
            {
                count++;
                IAmInside = true;
            }
        }
        else
        {
            IAmInside = false;
        }

    }

    cout << count << endl;

    return 0;
}