#include<bits/stdc++.h>
using namespace std;

void printer(stringstream & ss)
{
    string w;
    if(ss >> w)
    {
        printer(ss);
        cout << w << " ";        
    }


}

int main()
{
    string line;
    getline(cin,line);

    stringstream ss(line);
    printer(ss);


    return 0;
}