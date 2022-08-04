class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) 
    {
        int n=nums.size(),i=0,j=0,res=0;
        deque<int> q,q2;
        while(j<n)
        {
            while(!q.empty() and nums[q.back()]<=nums[j])
                q.pop_back();
            while(!q2.empty() and nums[q2.back()]>=nums[j])
                q2.pop_back();
            q.push_back(j);
            q2.push_back(j++);
            while(nums[q.front()]-nums[q2.front()]>limit)
            {
                if(q.front()<=i)
                    q.pop_front();
                if(q2.front()<=i)
                    q2.pop_front();
                i++;
            }
            res=max(res,j-i);
        }
        return res;
    }
};