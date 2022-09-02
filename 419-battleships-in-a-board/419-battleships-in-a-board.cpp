class Solution {
public:
    int countBattleships(vector<vector<char>>& board) 
    {
        int n=board.size(),m=board[0].size(),cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='X')
                {
                    bool poss=true;
                    if(i>0 and board[i-1][j]=='X')
                        poss=false;
                    else if(j>0 and board[i][j-1]=='X')
                        poss=false;
                    cnt+=poss;
                }
            }
        }
        return cnt;
    }
};