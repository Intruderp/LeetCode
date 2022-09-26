class Solution {
public:
    unordered_map<char,int> m;
    int cc=1,vis[26];
    vector<int> adj[26];
    void dfs(int src)
    {
        vis[src]=1;
        m[src]=cc;
        for(auto &it:adj[src])
        {
            if(vis[it]==0)
                dfs(it);
        }
    }
    bool equationsPossible(vector<string>& equations) 
    {
        for(auto &it:equations)
        {
            if(it[1]=='=')
            {
                adj[it[0]-'a'].push_back(it[3]-'a');
                adj[it[3]-'a'].push_back(it[0]-'a');
            }
        }
        for(int i=0;i<26;i++)
        {
            if(vis[i]==0)
            {
                dfs(i);
                cc++;
            }
        }
        for(auto &it:equations)
        {
            if(it[1]=='!' and m.count(it[0]-'a') and m.count(it[3]-'a') and m[it[0]-'a']==m[it[3]-'a'])
            return false;
        }
        return true;
    }
};