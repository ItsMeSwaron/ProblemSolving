#include<bits/stdc++.h>
using namespace std;

char grid[1010][1010];
vector <pair<int,int>> v = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
bool vis[1010][1010];
int dis[1010][1010];
int N, M;

bool ValidIndex(int i, int j)
{
    if(i < 0 || i >= N || j < 0 || j >= M)
    {
        return false;
    }
    return true;
}

int JeteParsi = 0;
int ans;

void BFS(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;

    while (!q.empty())
    {
        pair <int, int> par = q.front();
        int a = par.first;
        int b = par.second;
        q.pop();    

        if(grid[a][b] == 'D')
        {
            JeteParsi = 1;
            ans = dis[a][b];
        }

        for(int i=0;i<8;i++)
        {
            int ci = a + v[i].first;
            int cj = b + v[i].second;

            if(ValidIndex(ci,cj) == true && vis[ci][cj] == false)
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
            }
        }
    }    
}

int main()
{
    int T;
    cin >> T;

    for(int i=1;i<=T;i++)
    {
        JeteParsi = 0;
        
        cin >> N >> M;

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                grid[i][j] = '.'; 
            }
        }

        memset(vis,false,sizeof(vis));
        memset(dis,-1,sizeof(dis));

        int ki, kj, qi, qj;
        cin >> ki >> kj >> qi >> qj;

        grid[qi][qj] = 'D';

        BFS(ki, kj);

        if(JeteParsi == 1)
        {
            cout << ans << endl;
        }
        else
        {
            cout << "-1" << endl;
        }

    }


    return 0;
}