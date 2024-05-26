#include<bits/stdc++.h>
using namespace std;

char building[100][100];
vector <pair<int,int>> v = {{0,1},{0,-1},{-1,0},{1,0}};
bool vis[100][100];
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
    if(building[i][j] == '.' && building[i][j] == 'B')
    {
        return true;
    }
    return false;
}

bool paisi = false;

void DFS(int si, int sj)
{
    if(building[si][sj] == 'B')
    {
        paisi = true;
    }

    vis[si][sj] = true;

    for(int i=0;i<4;i++)
    {
        int ci = si + v[i].first;
        int cj = sj + v[i].second;
        if(ValidIndex(ci,cj) && ValidStep(ci,cj) && !vis[ci][cj])
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
            cin >> building[i][j];
        }
    }

    memset(vis,false,sizeof(vis));

    int si, sj;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(building[i][j] == 'A')
            {
                si = i;
                sj = j;
                i = N;
                break;
            }
        }
    }

    DFS(si,sj);
    
    if(paisi == true)
    {
        cout << "Yes" << endl;
    }
    return 0;
}