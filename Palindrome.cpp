#include<bits/stdc++.h>
using namespace std;

int Fixer(string Word, int x, int y)
{
    int a = Word[x];
    int b = Word[y];

    if(a + 32 == b)
    {
        return 1;
    }
    else if(b + 32 == a)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

int main()
{
    int T;
    cin >> T;

    for(int i=1;i<=T;i++)
    {
        int n;
        cin >> n;

        string S;

        cin >> S;

        sort(S.begin(),S.end());

        int x, y;
        x = 0;
        y = n - 1;

        int cost = 0;

        while(x < y)
        {
            if(S[x] != S[y])
            {
                cost = cost + Fixer(S,x,y);
            }
            x++;
            y--;
        }

        cout << cost << endl;
    }


    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string s;
//     cin >> s;

//     sort(s.begin(),s.end());

//     cout << s;

//     return 0;
// }