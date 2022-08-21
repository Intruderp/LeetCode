class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) 
    {
        int n=nums.size(),prev=-1,m;
        for(auto &group:groups)
        {
            bool found=false;
            m=group.size();
            for(int i=prev+1;i<=n-m;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(nums[i+j]!=group[j])
                        break;
                    if(j==m-1)
                        found=true;
                }
                if(found)
                {
                    prev=i+m-1;
                    break;
                }
            }
            if(!found)
                return false;
        }
        return true;
    }
};