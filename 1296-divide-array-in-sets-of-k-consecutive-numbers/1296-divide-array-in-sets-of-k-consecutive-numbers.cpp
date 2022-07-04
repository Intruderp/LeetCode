class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> m;
        for(auto &num:nums)
            m[num]++;
        while(m.size())
        {
            auto it=m.begin();
            int cur=it->first,y=it->second;
            while(y--)
            {
                int x=cur;
                for(int i=0;i<k;i++)
                {
                    if(m.count(x)==0)
                        return false;
                    m[x]--;
                    if(m[x]==0)
                        m.erase(x);
                    x++;
                }
            }
        }
        return true;
    }
};