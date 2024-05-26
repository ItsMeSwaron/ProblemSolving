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
    if(grid[i][j] == '.')
    {
        return true;
    }
    return false;
}

vector <int> comp;
int area = 0;

void DFS(int si, int sj)
{
    if(vis[si][sj] == false)
    {
        area++;
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
    getchar();

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> grid[i][j];
        }
    }

    memset(vis,false,sizeof(vis));

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(grid[i][j] == '.')
            {
                DFS(i,j);
                if(area != 0)
                {
                    comp.push_back(area);
                }
                area = 0;
            }
        }
    }

    if(!comp.empty())
    {
        sort(comp.begin(),comp.end());
    }

    if(comp.empty())
    {
        cout << "-1" << endl; 
    }
    else
    {
        cout << comp[0] << endl;
    }

    return 0;
}