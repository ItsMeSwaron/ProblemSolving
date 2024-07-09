#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector <pair<int,int>> v;

    while(n--)
    {
        int x, y;
        cin >> x >> y;

        v.push_back({x,y});
    }

    vector <double> distance;
    double dis;

    for(int i=0;i<v.size()-1;i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            dis = sqrt(pow(v[i].first-v[j].first,2) + pow(v[i].second-v[j].second,2));
            distance.push_back(dis);
        }
    } 

    sort(distance.begin(),distance.end());

    for(int i=0;i<v.size()-1;i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            dis = sqrt(pow(v[i].first-v[j].first,2) + pow(v[i].second-v[j].second,2));
            if(dis == distance[0])
            {
                cout << "(" << v[i].first << "," << v[i].second << ") & ";
                cout << "(" << v[j].first << "," << v[j].second << ") ---> " << fixed << setprecision(3) << distance[0] << endl;
                break;
            }
        }
    } 
    

    return 0;
}