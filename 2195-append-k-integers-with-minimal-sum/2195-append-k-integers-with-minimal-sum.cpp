class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long res=0,cur=1,x;
        sort(nums.begin(),nums.end());
        for(auto &num:nums)
        {
            if(num>cur)
            {
                if(num-cur<=k)
                {
                    k-=(num-cur);
                    x=num-1;
                    res+=x*(x+1)/2;
                    res-=(cur)*(cur-1)/2;
                }
                else
                {
                    x=cur+k-1;
                    k=0;
                    res+=x*(x+1)/2;
                    res-=(cur)*(cur-1)/2;
                }
            }
            cur=num+1;
        }
        if(k)
        {
            x=cur+k-1;
            res+=x*(x+1)/2;
            res-=(cur)*(cur-1)/2;
        }
        return res;
    }
};