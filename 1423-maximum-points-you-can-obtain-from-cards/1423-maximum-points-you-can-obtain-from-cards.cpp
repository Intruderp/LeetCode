class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size(),sum=0,res=0,i=0,j=n-k;
        for(int i=n-1;i>=n-k;i--)
        {
            sum+=cardPoints[i];
        }
        while(j<n)
        {
            res=max(res,sum);
            sum-=cardPoints[j];
            j++;
            sum+=cardPoints[i];
            i++;
        }
        res=max(res,sum);
        return res;
    }
};