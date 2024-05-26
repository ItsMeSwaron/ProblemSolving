#include<bits/stdc++.h>
using namespace std;

char jungle[100][100];
vector <pair<int,int>> v = {{0,1},{0,-1},{-1,0},{1,0}};
bool vis[100][100];
int dis[100][100];
int n;

bool ValidIndex(int i, int j)
{
    if(i >= n || i < 0 || j >= n || j < 0)
    {
        return false;
    }
    return true;
}

bool ValidStep(int i, int j)
{
    if(jungle[i][j] == 'E' || jungle[i][j] == 'P')
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
    dis[si][sj] = 0;

    while(!q.empty())
    {
        pair <int,int> p = q.front();
        int a = p.first;
        int b = p.second;
        q.pop();

        if(jungle[a][b] == 'E')
        {
            cout << dis[a][b] << endl;
        }

        for(int i=0;i<4;i++)
        {
            int ci = a + v[i].first;
            int cj = b + v[i].second;

            if(ValidIndex(ci,cj) && ValidStep(ci,cj) && !vis[ci][cj])
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
            }
        }
    }
}

int main()
{
    while(cin >> n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> jungle[i][j];
            }
        }

        memset(vis,false,sizeof(vis));
        memset(dis,-1,sizeof(dis));

        int si, sj;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(jungle[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                    i = n;
                    break;
                }   
            }
        }

        BFS(si,sj);


    }   

    return 0;
}