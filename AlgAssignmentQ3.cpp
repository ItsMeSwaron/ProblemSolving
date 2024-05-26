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
    if(Building[i][j] == '.' || Building[i][j] == 'B')
    {
        return true;
    }
    return false;
}

int paisi = 0;

void DFS(int si, int sj)
{
    if(Building[si][sj] == 'B')
    {
        paisi = 1;
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
            cin >> Building[i][j];
        }
    }

    memset(vis,false,sizeof(vis));

    int si, sj;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(Building[i][j] == 'A')
            {
                si = i;
                sj = j;
                i = N;
                break;
            }
        }
    }

    DFS(si,sj);

    if(paisi == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }

    return 0;
}