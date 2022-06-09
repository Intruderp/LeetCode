class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> lis;
        for(int &num:nums)
        {
            if(lis.size()==0)
                lis.push_back(num);
            else
            {
                if(num>lis.back())
                    lis.push_back(num);
                else
                {
                    auto it=lower_bound(lis.begin(),lis.end(),num);
                    *it=num;
                }
            }
            if(lis.size()==3)
                return true;
        }
        return false;
    }
};