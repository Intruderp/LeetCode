class Solution {
public:
    bool check(string &x,string &y)
    {
        int cnt=0,n=x.length();
        for(int i=0;i<n;i++)
        {
            cnt+=x[i]!=y[i];
        }
        return cnt==1;
    }
    void findPaths(vector<int> par[],vector<vector<string>> &res,vector<string> &path,vector<string> &wordList,int cur)
    {
        if(cur==-1)
        {
            res.push_back(path);
            reverse(res.back().begin(),res.back().end());
            return ;
        }
        for(auto &p:par[cur])
        {
            path.push_back(wordList[cur]);
            findPaths(par,res,path,wordList,p);
            path.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        if(find(wordList.begin(),wordList.end(),beginWord)==wordList.end())
            wordList.push_back(beginWord);
        int n=wordList.size(),start=-1,end=-1;
        vector<int> adj[n],dist(n,INT_MAX),par[n];
        vector<vector<string>> res;
        vector<string> path;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(check(wordList[i],wordList[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
            if(wordList[i]==endWord)
                end=i;
            if(wordList[i]==beginWord)
                start=i;
        }
        if(end==-1)
            return res;
        dist[start]=0;
        queue<int> q;
        q.push(start);
        par[start]={-1};
        while(!q.empty())
        {
            auto t=q.front();
            q.pop();
            for(auto &child:adj[t])
            {
                if(dist[child]>dist[t]+1)
                {
                    dist[child]=dist[t]+1;
                    par[child].clear();
                    par[child].push_back(t);
                    q.push(child);
                }
                else if(dist[child]==1+dist[t])
                    par[child].push_back(t);
            }
        }
        findPaths(par,res,path,wordList,end);
        return res;
        
    }
};