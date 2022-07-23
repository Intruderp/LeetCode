class Solution {
public:
    int countTriplets(vector<int>& nums) 
    {
        unordered_map<int,int> m;
        for(int &a:nums)
        {
            for(int &b:nums)
                m[a&b]++;
        }
        int res=0;
        for(int &num:nums)
        {
            for(auto &a:m)
            {
                if((a.first&num)==0)
                    res+=a.second;
            }
        }
        return res;
    }
};