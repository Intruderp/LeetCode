class Solution {
public:
    vector<int> findOriginalArray(vector<int>& c) 
    {
        vector<int> ans,v;
        unordered_map<int,int> m;
        for(int &i:c)
            m[i]++;
        int n=c.size();
        if(n%2)
            return {};
        sort(c.begin(),c.end());
        for(auto &it:c)
        {
            if(m[it]==0)
                continue;
            m[it]--;
            ans.push_back(it);
            if(m[it*2]>0)
            {
                m[2*it]--;
            }
            else
                return {};
        }
        return ans;
    }
};