#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    string S1, S2;
    cin >> S1 >> S2;
    
    if(S1 == "sick" && S2 == "sick") cout << 1 << endl;
    else if(S1 == "fine" && S2 == "fine") cout << 4 << endl;
    else if(S1 == "fine" && S2 == "sick") cout << 3 << endl;
    else if(S1 == "sick" && S2 == "fine") cout << 2 << endl;
    
    return 0;
}