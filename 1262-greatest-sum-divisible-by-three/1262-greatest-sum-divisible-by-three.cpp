class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int res=0,x=INT_MAX/2,y=x,x2=x,y2=x;
        for(int &num:nums)
        {
            res+=num;
            if(num%3==1)
            {
                if(num<x)
                {
                    x2=x;
                    x=num;
                }
                else
                    x2=min(x2,num);
            }
            if(num%3==2)
            {
                if(num<y)
                {
                    y2=y;
                    y=num;
                }
                else
                    y2=min(y2,num);
            }
        }
        if(res%3==0)
            return res;
        else if(res%3==1)
            res=max(res-x,res-y-y2);
        else
            res=max(res-y,res-x-x2);
        return res;
    }
};