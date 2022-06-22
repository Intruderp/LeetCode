class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        for(int &num:nums)
        {
            if(q.size()<k)
                q.push(num);
            else
            {
                if(q.top()<num)
                {
                    q.pop();
                    q.push(num);
                }
            }
        }
        return q.top();
    }
};