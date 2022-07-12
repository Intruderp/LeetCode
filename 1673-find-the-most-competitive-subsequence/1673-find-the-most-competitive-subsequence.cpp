class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        int i=0,cur=-1,n=nums.size();
        while(k)
        {
            while(!q.empty() and q.front()<=cur)
                q.pop_front();
            while(i<=n-k)
            {
                while(!q.empty() and nums[q.back()]>nums[i])
                    q.pop_back();
                q.push_back(i);
                i++;
            }
            res.push_back(nums[q.front()]);
            cur=q.front();
            k--;
        }
        return res;
    }
};