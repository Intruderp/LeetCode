class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;
        if(finalSum%2)
            return ans;
        int x=2;
        long long sum=2;
        ans.push_back(2);
        while(sum<=finalSum)
        {
            x+=2;
            sum+=x;
            ans.push_back(x);
        }
        int extra=sum-finalSum;
        if(extra==0)
            return ans;
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]>=extra)
            {
                extra=ans[i]-extra;
                ans.back()+=extra;
                ans.erase(ans.begin()+i);
                break;
            }
        }
        return ans;
    }
};