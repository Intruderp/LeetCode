class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int res=0,mn,mx;
        vector<int> freq(121,0);
        for(auto &age:ages)
            freq[age]++;
        for(auto &age:ages)
        {
            mx=age;
            mn=age/2+7+1;
            for(int i=mn;i<=mx;i++)
            {
                if(i<=100 or age>=100)
                {
                    if(i==age)
                        res+=max(0,freq[i]-1);
                    else
                        res+=freq[i];
                }
            }
        }
        return res;
    }
};