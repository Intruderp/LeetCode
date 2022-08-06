class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) 
    {
        int x=minutesToTest/minutesToDie+1,res=0,cur=1;
        while(cur<buckets)
        {
            res++;
            cur*=x;
        }
        return res;
    }
};