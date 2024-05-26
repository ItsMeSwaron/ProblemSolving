#include<bits/stdc++.h>
using namespace std;

char grid[1010][1010];
vector <pair<int,int>> v = {{0,1},{0,-1},{-1,0},{1,0}};
bool vis[1010][1010];
int N, M;

bool ValidIndex(int i, int j)
{
    if(i < 0 || i >= N || j < 0 || j >= M)
    {
        return false;
    }
    return true;
}

bool ValidStep(int i, int j)
{
    if(grid[i][j] == '.' || grid[i][j] == 'D')
    {
        return true;
    }
    return false;
}

int JeteParsi = 0;

void DFS(int si, int sj)
{
    if(grid[si][sj] == 'D')
    {
        JeteParsi = 1;
    }

    vis[si][sj] = true;

    for(int i=0;i<4;i++)
    {
        int ci = si + v[i].first;
        int cj = sj + v[i].second;

        if(ValidIndex(ci,cj) == true && ValidStep(ci,cj) == true && vis[ci][cj] == false)
        {
            DFS(ci,cj);
        }
    }
}

int main()
{
    cin >> N >> M;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> grid[i][j]; 
        }
    }

    memset(vis,false,sizeof(vis));

    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;

    grid[di][dj] = 'D';

    DFS(si, sj);

    if(JeteParsi == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}