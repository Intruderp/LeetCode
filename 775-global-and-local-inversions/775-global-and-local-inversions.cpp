class Solution {
public:
    void merge(int l,int mid,int r,vector<int> &nums,int &inv)
    {
        int l_sz=mid-l+1,r_sz=r-mid,L[l_sz+1],R[r_sz+1],j=0,k=0;
        for(int i=0;i<l_sz;i++)
        {
            L[i]=nums[i+l];
        }
        for(int i=0;i<r_sz;i++)
        {
            R[i]=nums[mid+1+i];
        }
        L[l_sz]=R[r_sz]=INT_MAX;
        for(int i=l;i<=r;i++)
        {
            if(R[k]<L[j])
            {
                nums[i]=R[k];
                inv+=l_sz-j;
                if(inv>nums.size())
                    return ;
                k++;
            }
            else
            {
                nums[i]=L[j];
                j++;
            }
        }
    }
    void mergeSort(int l,int r,vector<int> &nums,int &inv)
    {
        if(l>=r or inv>nums.size())
            return ;
        int mid=(l+r)/2;
        mergeSort(l,mid,nums,inv);
        mergeSort(mid+1,r,nums,inv);
        merge(l,mid,r,nums,inv);
    }
    bool isIdealPermutation(vector<int>& nums) {
        int localInv=0,n=nums.size(),globalInv=0;
        for(int i=0;i<n-1;i++)
            localInv+=nums[i]>nums[i+1];
        mergeSort(0,n-1,nums,globalInv);
        return globalInv==localInv;
    }
};