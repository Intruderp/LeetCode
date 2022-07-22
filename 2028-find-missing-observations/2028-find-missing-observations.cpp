class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum=mean*(rolls.size()+n)-accumulate(rolls.begin(),rolls.end(),0);
        vector<int> res;
        if(sum<n or sum>n*6)
            return res;
        int x=1,r;
        for(int i=1;i<=n;)
        {
            r=n-i;
            if(r*6<(sum-x))
            {
                x++;
                continue;
            }
            i++;
            sum-=x;
            res.push_back(x);
        }
        return res;
    }
};