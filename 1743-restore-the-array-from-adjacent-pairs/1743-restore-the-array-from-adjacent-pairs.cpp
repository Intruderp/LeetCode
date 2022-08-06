class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) 
    {
        int n=adjacentPairs.size()+1;
        unordered_map<int,vector<int>> m;
        for(auto &pair:adjacentPairs)
        {
            m[pair[0]].push_back(pair[1]);
            m[pair[1]].push_back(pair[0]);
        }
        vector<int> res(n);
        for(auto &it:m)
        {
            if(it.second.size()==1)
            {
                res[0]=it.first;
                res[1]=it.second[0];
                break;
            }
        }
        for(int i=2;i<n;i++)
        {
            if(m[res[i-1]][0]==res[i-2])
                res[i]=m[res[i-1]][1];
            else
                res[i]=m[res[i-1]][0];
        }
        return res;
    }
};