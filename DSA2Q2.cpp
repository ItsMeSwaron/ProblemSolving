#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b)
{
    return a.first > b.first;
}

int main()
{
    int n;
    cin >> n;

    int Weights[n];
    int Usefulness[n];
    
    for(int i=0;i<n;i++)
    {
        cin >> Weights[i];
    }

    for(int i=0;i<n;i++)
    {
        cin >> Usefulness[i];
    }

    int c;
    cin >> c; 
    int Capacities[c];

    for(int i=0;i<c;i++)
    {
        cin >> Capacities[i];
    }

    vector <pair<int,int>> UsefulnessPerKG;
    UsefulnessPerKG.resize(n);

    for(int i=0;i<n;i++)
    {
        UsefulnessPerKG[i] = {Usefulness[i] / Weights[i],i};
    }

    sort(UsefulnessPerKG.begin(),UsefulnessPerKG.end(),cmp);
    sort(Capacities,Capacities+c,greater<int>());

    for(auto x : UsefulnessPerKG)
    {
        cout << x.first << " ";
    }
    cout << endl;

    for(auto x : UsefulnessPerKG)
    {
        cout << x.second << " ";
    }
    cout << endl;

    int k = 0;
    int lav = 0;
    int helicopterUseKorchi;

    for(int i=0;i<n;i++)
    {
        if(Weights[UsefulnessPerKG[i].second] <= Capacities[k])
        {
            // niye nilaaam
            lav += Usefulness[UsefulnessPerKG[i].second];
            Capacities[k] -= Weights[UsefulnessPerKG[i].second];
        }
        else
        {
            // vango
            lav += UsefulnessPerKG[i].first * Capacities[k];
            Weights[UsefulnessPerKG[i].second] -= Capacities[k];
            i--;

            if(k < c-1) k++;
            else break;
        }
    }

    helicopterUseKorchi = k + 1;

    cout << lav << " " << helicopterUseKorchi << endl;


    return 0;
}