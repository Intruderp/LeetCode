class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2)
    {
        int i=0,j=0,x=0,y=0,n=word1.size(),m=word2.size();
        while(x<n and y<m)
        {
            while(i<word1[x].length() and j<word2[y].length())
            {
                if(word1[x][i]!=word2[y][j])
                    return false;
                i++;
                j++;
            }
            if(i==word1[x].length())
            {
                i=0;
                x++;
            }
            if(j==word2[y].length())
            {
                j=0;
                y++;
            }
        }
        return x==n and y==m;
    }
};