class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string,int> dist;
        sort(deadends.begin(),deadends.end());
        string src="0000";
        if(binary_search(deadends.begin(),deadends.end(),src))
           return -1;
        dist[src]=0;
        queue<string> q;
        q.push(src);
        while(!q.empty())
        {
            src=q.front();
            q.pop();
            if(src==target)
                return dist[src];
            for(int j=0;j<4;j++)
            {
                if(src[j]!='9')
                {
                    string child=src;
                    child[j]++;
                    if(!binary_search(deadends.begin(),deadends.end(),child) and dist.count(child)==0)
                    {
                        dist[child]=dist[src]+1;
                        q.push(child);
                    }
                }
                else
                {
                    string child=src;
                    child[j]='0';
                    if(!binary_search(deadends.begin(),deadends.end(),child) and dist.count(child)==0)
                    {
                        dist[child]=dist[src]+1;
                        q.push(child);
                    }
                }
                if(src[j]!='0')
                {
                    string child=src;
                    child[j]--;
                    if(!binary_search(deadends.begin(),deadends.end(),child) and dist.count(child)==0)
                    {
                        dist[child]=dist[src]+1;
                        q.push(child);
                    }
                }
                else
                {
                    string child=src;
                    child[j]='9';
                    if(!binary_search(deadends.begin(),deadends.end(),child) and dist.count(child)==0)
                    {
                        dist[child]=dist[src]+1;
                        q.push(child);
                    }
                }
            }
        }
        return -1;
    }
};