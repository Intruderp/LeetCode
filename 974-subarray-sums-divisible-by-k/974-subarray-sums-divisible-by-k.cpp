class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0]=1;
        int sum=0,cnt=0,r;
        for(int &num:nums)
        {
            sum+=num;
            r=(sum)%k;
            if(r<0)
                r+=k;
            if(m.count(r))
                cnt+=m[r];
            m[r]++;
        }
        return cnt;
    }
};