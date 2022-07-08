class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size(),row,col,num,newJ;
        vector<int> dist(n*n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,1});
        while(!q.empty())
        {
            auto t=q.top();
            q.pop();
            if(dist[t.second]<t.first)
                continue;
            for(int j=t.second+1;j<=min(n*n,t.second+6);j++)
            {
                row=(j-1)/n;
                if(row%2)
                {
                    num=(row+1)*n;
                    col=num-j;
                }
                else
                {
                    num=row*n+1;
                    col=j-num;
                }
                if(board[n-row-1][col]==-1)
                {
                    if(dist[j]>t.first+1)
                    {
                        dist[j]=t.first+1;
                        q.push({dist[j],j});
                    }
                }
                else
                {
                    newJ=board[n-row-1][col];
                    if(dist[newJ]>t.first+1)
                    {
                        dist[newJ]=t.first+1;
                        q.push({dist[newJ],newJ});
                    }
                }
            }
        }
        return dist[n*n]==INT_MAX ? -1 : dist[n*n];
    }
};