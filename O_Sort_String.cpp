#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;

    getchar();

    char S;

    int alpha[26] = {0};

    for(int i=0;i<N;i++)
    {
        cin >> S;
        int num = S - 97;
        alpha[num]++;
    }

    for(int i=0;i<26;i++)
    {
        if(alpha[i] > 0)
        {
            while(alpha[i] > 0)
            {
                cout << char(i + 97);
                // alpha[i]--;
            }
        }
    }
    

    return 0;
}