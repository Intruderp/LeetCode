class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2)
    {
        vector<int> diff(100001,0);
        int n=nums1.size(),d=0,mx;
        long long res=0,x;
        for(int i=0;i<n;i++)
        {
            diff[abs(nums1[i]-nums2[i])]++;
            d=max(d,abs(nums1[i]-nums2[i]));
        }
        k1+=k2;
        mx=d;
        while(d and k1)
        {
            if(diff[d]>k1)
            {
                diff[d]-=k1;
                diff[d-1]+=k1;
                k1=0;
            }
            else
            {
                k1-=diff[d];
                diff[d-1]+=diff[d];
                diff[d]=0;
            }
            d--;
        }
        for(int i=1;i<=mx;i++)
        {
            x=i;
            res+=x*x*diff[i];
        }
        return res;
    }
};