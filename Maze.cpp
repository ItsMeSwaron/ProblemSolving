#include<bits/stdc++.h>
using namespace std;

char home[1010][1010];
vector <pair<int,int>> v = {{0,1},{0,-1},{-1,0},{1,0}};
bool vis[1010][1010];
pair<int,int> par[1010][1010];
int n, m;

bool ValidIndex(int i, int j)
{
    if(i >= n || i < 0 || j >= m || j < 0)
    {
        return false;
    }
    return true;
}

bool ValidStep(int i, int j)
{
    if(home[i][j] == 'D' || home[i][j] == '.')
    {
        return true;
    }
    return false;
}

void BFS(int si, int sj)
{
    queue <pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;
    par[si][sj].first = -1;
    par[si][sj].second = -1;

    while(!q.empty())
    {
        pair <int,int> p = q.front();
        int a = p.first;
        int b = p.second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int ci = a + v[i].first;
            int cj = b + v[i].second;

            if(ValidIndex(ci,cj) && ValidStep(ci,cj) && !vis[ci][cj])
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
                par[ci][cj].first = a;
                par[ci][cj].second = b;
            }
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
            cin >> home[i][j];
        }
    }

    memset(vis,false,sizeof(vis));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            par[i][j].first = -1;
            par[i][j].second = -1;
        }
    }
    
    int si, sj, di, dj;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(home[i][j] == 'R')
            {
                si = i;
                sj = j;
                i = n;
                break;
            }   
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(home[i][j] == 'D')
            {
                di = i;
                dj = j;
                i = n;
                break;
            }   
        }
    }

    BFS(si,sj); 

    int i, j;
    i = par[di][dj].first;
    j = par[di][dj].second;

    while(i != -1 && j != -1)
    {
        int tmpi = i;
        int tmpj = j;
        home[tmpi][tmpj] = 'X';
        i = par[tmpi][tmpj].first;
        j = par[tmpi][tmpj].second;
    }

    home[si][sj] = 'R';

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout << home[i][j];
        }
        cout << endl;
    }

    return 0;
}