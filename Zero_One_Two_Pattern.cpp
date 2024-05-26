#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;

    int len = (2*N)-1;
    char Mat[len][len];
    char TheVal = '1';
    int level = 1;

    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            if(i == j)
            {
                Mat[i][j] = TheVal;
            }
            
            if(i+j == len-1)
            {
                Mat[i][j] = TheVal;
            }
            
            if(i != j && i+j != len - 1)
            {
                Mat[i][j] = ' ';
            }
        }

        if(level == 1)
        {
            level = 2;
        }
        else if(level == 2)
        {
            level = 3;
        }
        else
        {
            level = 1;
        }

        if(level == 1)
        {
            TheVal = '1';
        }
        else if(level == 2)
        {
            TheVal = '2';
        }
        else
        {
            TheVal = '0';
        }
    }

    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            cout << Mat[i][j];
        }
        cout << endl;
    }

    return 0;
}