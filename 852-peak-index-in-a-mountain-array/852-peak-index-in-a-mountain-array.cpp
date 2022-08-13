class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int n=arr.size(),low=1,high=n-2,mid;
        while(low<=high)
        {
            mid=(high+low)/2;
            if(arr[mid+1]<arr[mid] and arr[mid]>arr[mid-1])
                return mid;
            if(arr[mid]>arr[mid-1] and arr[mid+1]>arr[mid])
                low=mid+1;
            else
                high=mid-1;
        }
        return -1;
    }
};