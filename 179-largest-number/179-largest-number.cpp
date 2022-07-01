class Solution {
public:
    static bool comp(int a,int b)
    {
        string x=to_string(a),y=to_string(b);
        return x+y>y+x;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),comp);
        string res;
        for(auto &num:nums)
        {
            if(res.length()==0 and num==0)
                continue;
            res+=to_string(num);
        }
        return res.length()>0 ? res : "0";
    }
};