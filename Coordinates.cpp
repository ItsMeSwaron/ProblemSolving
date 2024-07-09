#include<bits/stdc++.h>
using namespace std;
int main()
{
    int cds;
    cin >> cds;
    vector <pair<int,int>> v;

    while(cds--)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x,y});
    }

    double dis;

    vector <double> D;

    for(int i=0;i<v.size()-1;i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            dis = sqrt(pow(v[i].first-v[j].first,2) + pow(v[i].second - v[j].second,2));
            D.push_back(dis);
        }
    }

    sort(D.begin(),D.end());

    vector <int> ans;
    double tmp;

    for(int i=0;i<v.size()-1;i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            tmp = sqrt(pow(v[i].first-v[j].first,2) + pow(v[i].second - v[j].second,2));

            if(tmp == D[0])
            {
                ans.push_back(v[i].first);
                ans.push_back(v[i].second);
                ans.push_back(v[j].first);
                ans.push_back(v[j].second);            
            }
        }
    }    

    cout << "The closest pair is point (" << ans[0] << "," << ans[1] << ") and point (" << ans[2] << "," << ans[3] << ")." << "Their distance is " << fixed << setprecision(3) << D[0] << endl; 

    return 0;
}