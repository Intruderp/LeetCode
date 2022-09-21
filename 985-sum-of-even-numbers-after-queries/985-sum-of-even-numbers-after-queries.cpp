class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int evenSum=0;
        for(auto &num:nums)
        {
            evenSum+= num%2 ? 0:num;
        }
        vector<int> res;
        for(auto &query:queries)
        {
            int x=nums[query[1]];
            nums[query[1]]+=query[0];
            if(nums[query[1]]%2==0)
            {
                if(x%2)
                    evenSum+=nums[query[1]];
                else
                    evenSum+=query[0];
            }
            else if(x%2==0)
            {
                evenSum-=x;
            }
            res.push_back(evenSum);
        }
        return res;
    }
};