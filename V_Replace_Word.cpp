#include<bits/stdc++.h>
using namespace std;
int main()
{
    string line;
    getline(cin,line);

    while(line.find("EGYPT") != -1)
    {
        line.replace(line.find("EGYPT"),5," ");  
    }

    cout << line << endl;


    return 0;
}