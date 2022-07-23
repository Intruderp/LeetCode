class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int localInv=0,n=nums.size(),globalInv=0,cnt=0;
        vector<int> pre(n,0);
        for(int i=0;i<n;i++)
        {
            cnt+=pre[i];
            if(i+1<n)
                localInv+=nums[i]>nums[i+1];
            globalInv+=max(0,nums[i]-cnt);
            if(globalInv>n)
                break;
            pre[nums[i]]+=1;
            if(i>=nums[i])
                cnt++;
        }
        return globalInv==localInv;
    }
};