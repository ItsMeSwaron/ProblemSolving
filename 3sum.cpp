#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> nums;

    int n;
    cin >> n;

    while(n--)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    int target;
    cin >> target;

    vector <pair<int,int>> ans;

    for(int i=0;i<nums.size()-2;i++)
    {
        for(int j=i+1;j<nums.size()-1;j++)
        {
            for(int k=j+1;k<nums.size();k++)
            {
                ans.push_back({abs(target - (nums[i] + nums[j] + nums[k])), nums[i] + nums[j] + nums[k]});                    
            }           
        }       
    }    

    for(int i=0;i<ans.size()-1;i++)
    {
        for(int j=i+1;j<ans.size();j++)
        {
            if(ans[i].first > ans[j].first)
            {
                swap(ans[i],ans[j]);
            }
        }
    }
    
    cout << ans[0].second << endl;

    return 0;
}

