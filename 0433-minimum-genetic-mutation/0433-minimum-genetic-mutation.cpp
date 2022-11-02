class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) 
    {
        sort(bank.begin(),bank.end());
        if(binary_search(bank.begin(),bank.end(),start)==0)
            bank.push_back(start);
        int n=bank.size(),x,y,z=-1;
        vector<int> adj[n],dist(n,100);
        for(int i=0;i<n;i++)
        {
            if(bank[i]==start)
                y=i;
            if(bank[i]==end)
                z=i;
            for(int j=i+1;j<n;j++)
            {
                x=0;
                for(int k=0;k<8;k++)
                {
                    x+=bank[i][k]!=bank[j][k];
                    if(x>1)
                        break;
                }
                if(x==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        queue<int> q;
        q.push(y);
        dist[y]=0;
        while(q.empty()==0)
        {
            int f=q.front();
            q.pop();
            for(auto &it:adj[f])
            {
                if(dist[it]==100)
                {
                    q.push(it);
                    dist[it]=1+dist[f];
                    if(it==z)
                        return dist[z];
                }
            }
        }
        return -1;
    }
};