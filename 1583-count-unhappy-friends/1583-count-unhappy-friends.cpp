class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int res=0,z;
        vector<int> p(n);
        vector<vector<int>> posn(n,vector<int>(n));
        for(auto &pair:pairs)
        {
            p[pair[0]]=pair[1];
            p[pair[1]]=pair[0];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-1;j++)
                posn[i][preferences[i][j]]=j;
        }
        for(auto &pair:pairs)
        {
            for(auto &x:preferences[pair[0]])
            {
                if(pair[1]==x)
                    break;
                z=p[x];
                if(posn[x][pair[0]]<posn[x][z])
                {
                    res++;
                    break;
                }
            }
            for(auto &x:preferences[pair[1]])
            {
                if(pair[0]==x)
                    break;
                z=p[x];
                if(posn[x][pair[1]]<posn[x][z])
                {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};