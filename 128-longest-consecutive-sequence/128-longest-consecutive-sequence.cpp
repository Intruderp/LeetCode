class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int ans=0,l1=0,l2=0,x=0,y=0;
        unordered_set<int> s1,s2;
        for(int &i:nums)
            s1.insert(i);
        for(int &i:nums)
        {
            if(s2.count(i))
                continue;
            l1=1,l2=0,x=i+1,y=i-1;
            while(s1.count(x))
            {
                l1++;
                s2.insert(x);
                x++;
            }
            while(s1.count(y))
            {
                l2++;
                s2.insert(y);
                y--;
            }
            ans=max(ans,l1+l2);
        }
        return ans;
    }
};