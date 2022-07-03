class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> m;
        for(auto &match:matches)
        {
            m[match[0]]+=0;
            m[match[1]]++;
        }
        vector<vector<int>> res(2);
        for(auto &it:m)
        {
            if(it.second==0)
                res[0].push_back(it.first);
            else if(it.second==1)
                res[1].push_back(it.first);
        }
        return res;
    }
};