class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) 
    {
        vector<int> ans;
        int b,g;
        for(int i:nums)
        {
            while(ans.size() and __gcd(ans.back(),i)>1)
            {
                i=((long long)i*ans.back())/__gcd(ans.back(),i);
                ans.pop_back();
            }
            ans.push_back(i);
        }
        return ans;
    }
};