class Solution {
public:
    int countTriplets(vector<int>& nums) 
    {
        int mx=1<<16;
        vector<int> cnt(mx,0);
        for(int &a:nums)
        {
            for(int &b:nums)
                cnt[a&b]++;
        }
        int res=0;
        for(int &num:nums)
        {
            for(int i=0;i<mx;i++)
                res+=(num&i)==0 ? cnt[i]:0;
        }
        return res;
    }
};