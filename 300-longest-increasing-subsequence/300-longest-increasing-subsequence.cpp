class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> ans;
        for(int &i:nums)
        {
            if(ans.size()==0)
                ans.push_back(i);
            else if(ans.back()<i)
                ans.push_back(i);
            else
            {
                auto it=lower_bound(ans.begin(),ans.end(),i);
                *it=i;
            }
        }
        return ans.size();
    }
};