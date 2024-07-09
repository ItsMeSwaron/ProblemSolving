#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;

    int numRows;
    cin >> numRows;

    vector <vector<char>> v;
    v.resize(numRows);

    int phase = 0;
    int j = 0;

    for(int i=0;i<s.size();i++)
    {
        if(phase == 0)
        {
            v[j].push_back(s[i]);
            j++;

            if(j == numRows)
            {
                phase = 1;
                j = j - 2;
            }
        }
        else
        {
           v[j].push_back(s[i]);
            j--;

            if(j == -1)
            {
                phase = 0;
                j = j + 2;
            } 
        }
    }

    string ans = "";

    for(int i=0;i<v.size();i++)
    {
        for(char x : v[i])
        {
            ans.append(1,x);
        }
    }

    cout << ans << endl;

    return 0;
}