class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size(),sum=0,res=0;
        vector<int> suff(n,0);
        for(int i=n-1;i>=0;i--)
        {
            sum+=cardPoints[i];
            suff[i]=sum;
        }
        sum=0;
        for(int i=0;i<k;i++)
        {
            res=max(res,sum+suff[n-k+i]);
            sum+=cardPoints[i];
        }
        res=max(res,sum);
        return res;
    }
};