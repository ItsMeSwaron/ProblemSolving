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

vector <int> apart;
int roomz = 0;

void DFS(int si, int sj)
{
    if(vis[si][sj] == false)
    {
        roomz++;
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
            cin >> Building[i][j];
        }
    }

    memset(vis,false,sizeof(vis));

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(Building[i][j] == '.' && visit[i][j] == false)
            {
                DFS(i,j);
                if(roomz != 0)
                {
                    apart.push_back(roomz);
                }
                roomz = 0;
            }
        }
    }

    if(!apart.empty())
    {
        sort(apart.begin(),apart.end());
    }

    if(apart.empty())
    {
        cout << "0" << endl; 
    }
    else
    {
        for(int x : apart)
        {
            cout << x << " ";
        }    
    }

    cout << endl;

    return 0;
}