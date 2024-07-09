#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <long long int> v1;
    vector <long long int> v2;

    long long int s1;
    cin >> s1;

    long long int s2;
    cin >> s2;

    while(s1--)
    {
        long long int x;
        cin >> x;
        
        v1.push_back(x);
    }

    while(s2--)
    {
        long long int x;
        cin >> x;

        v2.push_back(x);
    }

    if(is_sorted(v1.begin(), v1.end()) && is_sorted(v2.begin(), v2.end()))
    {
        vector <long long int> mrg;

        mrg = v1;

        while(!v2.empty())
        {
            mrg.push_back(v2[0]);
            v2.erase(v2.begin());
        }

        for(long long int x : mrg)
        {
            cout << x << " ";
        }
    }
    else
    {
        long long int boro1 = INT_MIN;

        for(long long int i=0;i<v1.size();i++)
        {
            if(v1[i] > boro1)
            {
                boro1 = v1[i];
            }
        }
    
        int boro2 = INT_MIN;

        for(long long int i=0;i<v2.size();i++)
        {
            if(v2[i] > boro2)
            {
                boro2 = v2[i];
            }
        }

        if(boro1 > boro2)
        {
            while(!v1.empty())
            {
                cout << v1.back() << " ";
                v1.pop_back();
            }
        }
        else
        {
            while(!v2.empty())
            {
                cout << v2.back() << " ";
                v2.pop_back();
            }
        }
    }


    return 0;
}