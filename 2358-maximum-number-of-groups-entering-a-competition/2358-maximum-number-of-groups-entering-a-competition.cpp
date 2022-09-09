class Solution {
public:
    int maximumGroups(vector<int>& grades)
    {
        int n=grades.size(),low=1,high=n,maxG=0;
        long mid;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(mid*(mid+1)<=2*n)
            {
                maxG=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return maxG;
    }
};