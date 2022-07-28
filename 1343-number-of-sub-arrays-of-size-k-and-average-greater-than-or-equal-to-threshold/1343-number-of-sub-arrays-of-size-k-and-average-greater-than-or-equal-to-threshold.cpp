class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size(),i=0,j=0,sum=0,res=0;
        while(j<n)
        {
            while(j-i+1<=k)
            {
                sum+=arr[j];
                j++;
            }
            res+=sum/k>=threshold;
            sum-=arr[i];
            i++;
        }
        return res;
    }
};