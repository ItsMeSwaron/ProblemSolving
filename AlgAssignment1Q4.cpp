#include<bits/stdc++.h>
using namespace std;

char Building[1010][1010];
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
    if(Building[i][j] == '.')
    {
        return true;
    }
    return false;
}

int apart = 0;

void DFS(int si, int sj)
{
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
    getchar();

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> Building[i][j];
        }
    }

    memset(vis,false,sizeof(vis));

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(Building[i][j] == '.')
            {
                if(vis[i][j] == false)
                {
                    apart++;
                }
                DFS(i,j);
            }
        }
    }

    cout << apart << endl;

    return 0;
}