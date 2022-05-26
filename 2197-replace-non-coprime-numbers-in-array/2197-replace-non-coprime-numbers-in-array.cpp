class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) 
    {
        vector<int> ans;
        int b,g;
        for(int i:nums)
        {
            g=1;
            if(ans.size())
                g=__gcd(i,ans.back());
            while(ans.size() and g>1)
            {
                i=((long long)i*ans.back())/g;
                ans.pop_back();
                if(ans.size())
                    g=__gcd(i,ans.back());
            }
            ans.push_back(i);
        }
        return ans;
    }
};