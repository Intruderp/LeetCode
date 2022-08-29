class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        int res=0;
        long sum=accumulate(nums.begin(),nums.end(),0ll);
        double curSum=sum;
        for(auto &num:nums)
            pq.push(num);
        while(curSum*2>sum)
        {
            double t=pq.top();
            pq.pop();
            curSum-=t/2;
            pq.push(t/2);
            res++;
        }
        return res;
    }
};