#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int i,j,k;
        vector<int>v;
        for(i=0;i<n;i++)
        {
            if(v.empty())
            {
                v.push_back(nums[i]);
            }
            else
            {
                auto x = lower_bound(v.begin(),v.end(),nums[i]);
                if(x==v.end())
                {
                    v.push_back(nums[i]);
                }
                else
                {
                    *x = nums[i];
                }
            }
        }

        return v.size();
    }
};

int main()
{
    Solution x;
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &x:v)
    {
        cin>>x;
    }
    cout<< x.lengthOfLIS(v) <<endl;
}
