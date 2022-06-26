class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int res=0,bit;
        for(int i=0;i<32;i++)
        {
            bit=0;
            for(int &num:nums)
            {
                if((1<<i)&num)
                {
                    bit=1;
                    break;
                }
            }
            if(bit)
                res|=(1<<i);
        }
        return res;
    }
};