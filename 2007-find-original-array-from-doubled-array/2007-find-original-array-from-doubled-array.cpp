class Solution {
public:
    vector<int> findOriginalArray(vector<int>& c) 
    {
        vector<int> ans,v;
        unordered_map<int,int> m;
        for(int &i:c)
            m[i]++;
        int n=c.size();
        sort(c.begin(),c.end());
        for(auto &it:c)
        {
            int x=0;
            if(it==0)
                x=1;
            if(m[2*it]>x and m[it]>0)
            {
                ans.push_back(it);
                m[it*2]--;
                m[it]--;
            }
        }
        if(ans.size()!=(n+1)/2)
        return v;
        return ans;
    }
};