class Solution {
public:
    bool valid(vector<vector<char>>& board,int r,int c)
    {
        int cnt[9]={0};
        for(int i=r;i<r+3;i++)
        {
            for(int j=c;j<c+3;j++)
            {
                if(board[i][j]=='.')
                    continue;
                if(cnt[board[i][j]-'1'])
                    return false;
                cnt[board[i][j]-'1']++;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++)
        {
            int cnt[9]={0};
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='.')
                    continue;
                if(cnt[board[i][j]-'1'])
                    return false;
                cnt[board[i][j]-'1']++;
            }
        }
        for(int j=0;j<m;j++)
        {
            int cnt[9]={0};
            for(int i=0;i<n;i++)
            {
                if(board[i][j]=='.')
                    continue;
                if(cnt[board[i][j]-'1'])
                    return false;
                cnt[board[i][j]-'1']++;
            }
        }
        for(int i=0;i<n;i+=3)
        {
            for(int j=0;j<m;j+=3)
            {
                if(!valid(board,i,j))
                    return false;
            }
        }
        return true;
    }
};