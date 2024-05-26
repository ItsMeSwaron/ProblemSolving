#include<bits/stdc++.h>
using namespace std;

char A[20][20];
bool vis[20][20];
vector <pair<int,int>> v = {{0,1},{0,-1},{-1,0},{1,0}};
int n, m;

bool valid(int i, int j)
{
    if(i<0 || i>=n || j<0 || j>=m)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void DFS(int si, int sj)
{
    cout << si << " " << sj << endl;
    vis[si][sj] = true;

    for(int i=0;i<4;i++)
    {
        int ci = si + v[i].first;
        int cj = sj + v[i].second;

        if(valid(ci,cj) == true && vis[ci][cj] == false)
        {
            DFS(ci,cj);   
        }
    }
}

int main()
{
    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> A[i][j];
        }
    }

    int si, sj;
    cin >> si >> sj;

    memset(vis,false,sizeof(vis));

    DFS(si,sj);

    return 0;
}