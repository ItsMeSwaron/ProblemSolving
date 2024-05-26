#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;

    if(N == 1)
    {
        cout << "1" << endl;
        return 0;
    }

    int Mat[N][N];
    int level = 1;
    int RowValz = 1;
    int ColValz = 2;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(level == 1)
            {
                Mat[i][j] = RowValz;
                RowValz++;
            }
            else if(level != N)
            {
                if(j == 0)
                {
                    Mat[i][j] = ColValz;
                    ColValz++;
                }
                else if(j == N-1)
                {
                    Mat[i][j] = N; 
                }
                else
                {
                    Mat[i][j] = 0;
                }
            }
            else if(level == N)
            {
                Mat[i][j] = N;
            }
        }
        level++;
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(Mat[i][j] != 0)
            {
                cout << Mat[i][j];
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}