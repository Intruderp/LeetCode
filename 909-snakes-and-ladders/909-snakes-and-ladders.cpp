class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size(),row,col,num,newJ;
        vector<int> dist(n*n+1,-1);
        queue<int> q;
        q.push(1);
        dist[1]=0;
        while(!q.empty())
        {
            auto t=q.front();
            if(t==n*n)
                return dist[n*n];
            q.pop();
            for(int j=t+1;j<=min(n*n,t+6);j++)
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
                    if(dist[j]==-1)
                    {
                        dist[j]=dist[t]+1;
                        q.push(j);
                    }
                }
                else
                {
                    newJ=board[n-row-1][col];
                    if(dist[newJ]==-1)
                    {
                        dist[newJ]=dist[t]+1;
                        q.push(newJ);
                    }
                }
            }
        }
        return dist[n*n];
    }
};