class Solution {
public:
    bool judgeSquareSum(int c) 
    {
        unordered_set<int> s;
        for(long i=0;i*i<=c;i++)
            s.insert(i*i);
        for(long a=0;a*a<=c;a++)
        {
            if(s.count(c-a*a))
                return true;
        }
        return false;
    }
};