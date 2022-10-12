class Solution {
public:
    int n,m,x,y,res=INT_MAX;
    vector<int> dir{1,0,-1,0,1};
    bool valid(int &i,int &j)
    {
        return i>=0 and i<n and j>=0 and j<m;
    }
    void fill(vector<vector<int>> &dist,int x)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                dist[i][j]=x;
        }
    }
    int help(vector<vector<int>> &keys,vector<string>&grid)
    {
        vector<vector<int>> dist(n,vector<int>(m,-1));
        dist[x][y]=0;
        queue<pair<int,int>> q;
        q.push({x,y});
        int k=0,ans=0;
        unordered_set<char> lock;
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            for(int d=0;d<4;d++)
            {
                int i=f.first+dir[d],j=f.second+dir[d+1];
                if(valid(i,j) and dist[i][j]==-1 and grid[i][j]!='#')
                {
                    if(grid[i][j]>='a' and grid[i][j]<='z')
                    {
                        if(keys[k][0]==i and keys[k][1]==j)
                        {
                            dist[i][j]=1+dist[f.first][f.second];
                            ans+=dist[i][j];
                            k++;
                            if(k==keys.size() or ans>res)
                                return ans;
                            lock.insert(toupper(grid[i][j]));
                            fill(dist,-1);
                            queue<pair<int,int>> temp;
                            dist[i][j]=0;
                            temp.push({i,j});
                            q=temp;
                            break;
                        }
                        else if(lock.count(toupper(grid[i][j])))
                        {
                            dist[i][j]=1+dist[f.first][f.second];
                            q.push({i,j});
                        }
                    }
                    else if(grid[i][j]>='A' and grid[i][j]<='Z')
                    {
                        if(lock.count(grid[i][j]))
                        {
                            dist[i][j]=1+dist[f.first][f.second];
                            q.push({i,j});
                        }
                    }
                    else if(grid[i][j]=='.' or grid[i][j]=='@')
                    {
                        dist[i][j]=1+dist[f.first][f.second];
                        q.push({i,j});
                    }
                }
            }
        }
        return INT_MAX;
    }
    int shortestPathAllKeys(vector<string>& grid) 
    {
        n=grid.size(),m=grid[0].size();
        vector<vector<int>> keys;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='@')
                    x=i,y=j;
                else if(grid[i][j]>='a' and grid[i][j]<='z')
                    keys.push_back({i,j});
            }
        }
        sort(keys.begin(),keys.end());
        do
        {
            res=min(res,help(keys,grid));
        }while(next_permutation(keys.begin(),keys.end()));
        return res==INT_MAX ? -1:res;
    }
};