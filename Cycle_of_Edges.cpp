#include<bits/stdc++.h>
using namespace std;

int par[1000006];
int Level[1000006];

void DSUInitialize(int N)
{
    for(int i=1;i<=N;i++)
    {
        par[i] = -1;
        Level[i] = 1;
    }
}

int DSULeaderFinder(int node)
{
    if(par[node] == -1)
    {
        return node;
    }
    int leader = DSULeaderFinder(par[node]);
    par[node] = leader;
    return leader;
}

void DSUUnionBYLevel(int node1, int node2)
{
    int leaderA = DSULeaderFinder(node1);
    int leaderB = DSULeaderFinder(node2);

    if(Level[leaderA] > Level[leaderB])
    {
        par[leaderB] = leaderA; 
    }
    else if (Level[leaderB] > Level[leaderA])
    {
        par[leaderA] = leaderB;
    }
    else
    {
        par[leaderA] = leaderB;
        Level[leaderB]++;
    }    
}

int main()
{
    int N, E;
    cin >> N >> E;

    DSUInitialize(N);

    int count = 0;

    while(E--)
    {
        int A, B;
        cin >> A >> B;

        if(DSULeaderFinder(A) == DSULeaderFinder(B))
        {
            count++;
        }
        else
        {
            DSUUnionBYLevel(A,B);
        }
    }

    cout << count << endl;

    return 0;
}