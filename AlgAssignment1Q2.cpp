#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> v;
    int N, E;
    cin >> N >> E;

    int Mat[N][N];
    memset(Mat,0,sizeof(Mat));

    while(E--)
    {
        int a, b;
        cin >> a >> b;

        Mat[a][b] = 1;
        Mat[b][a] = 1;
    }

    int Q;
    cin >> Q;

    for(int i=1;i<=Q;i++)
    {
        int X;
        cin >> X;

        for(int j=0;j<N;j++)
        {
            if(Mat[X][j] == 1)
            {
                v.push_back(j);
            }
        }

        if(!v.empty())
        {
            sort(v.begin(),v.end(),greater<int>());
        }

        if(!v.empty())
        {
            for(int child : v)
            {
                cout << child << " ";
            }
        }
        else
        {
            cout << "-1";
        }

        v.clear();

        cout << endl;

    }

    return 0;
}