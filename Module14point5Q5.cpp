#include<bits/stdc++.h>
using namespace std;

char basha[1010][1010];
vector <pair<int,int>> v = {{0,1},{0,-1},{-1,0},{1,0}};
bool vis[1010][1010];
int level[1010][1010];
int ans;

bool ValidIndex(int i, int j, int n)
{
    if(i < 0 || i >= n || j < 0 || j >= n)
    {
        return false;
    }
    return true;
}

bool validStep(int i, int j)
{
    if(basha[i][j] == 'R' || basha[i][j] == 'T' || basha[i][j] == 'D')
    {
        return true;
    }
    return false;
}

void BFS2(int si, int sj, int n)
{
    queue <pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while(!q.empty())
    {
        pair <int,int> p = q.front();
        int a = p.first;
        int b = p.second;
        q.pop();

        if(basha[a][b] == 'D')
        {
            ans = ans + level[a][b];
            break;
        }

        for(int i=0;i<4;i++)
        {
            int ci = a + v[i].first;
            int cj = b + v[i].second;
            if(ValidIndex(ci,cj,n) && validStep(ci,cj) && !vis[ci][cj])
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[a][b] + 1;
            }
        }
    }

}

void BFS(int si, int sj, int n)
{
    queue <pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;
    level[si][sj] = 0;
    int a, b;

    while(!q.empty())
    {
        pair <int,int> p = q.front();
        a = p.first;
        b = p.second;
        q.pop();

        if(basha[a][b] == 'R')
        {
            memset(vis,false,sizeof(vis));
            ans = level[a][b];
            memset(level,-1,sizeof(level));
            BFS2(a,b,n);
            break;
        }

        for(int i=0;i<4;i++)
        {
            int ci = a + v[i].first;
            int cj = b + v[i].second;
            if(ValidIndex(ci,cj,n) && validStep(ci,cj) && !vis[ci][cj])
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[a][b] + 1;
            }
        }
    }

    if(basha[a][b] != 'R')
    {
        ans = -1;
    }

}


int main()
{
    int T;
    cin >> T;

    for(int i=1;i<=T;i++)
    {
        int n;
        cin >> n;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> basha[i][j];
            }
        }

        memset(vis,false,sizeof(vis));
        memset(level,-1,sizeof(level));

        int si, sj;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(basha[i][j] == 'M')
                {
                    si = i;
                    sj = j;
                    i = n;
                    break;
                }
            }
        }

        BFS(si,sj,n);
        cout << ans << endl;

    }

    return 0;
}