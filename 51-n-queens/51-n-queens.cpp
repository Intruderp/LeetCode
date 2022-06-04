class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<int>> dir={{1,1},{-1,-1},{-1,1},{1,-1}};
    bool isValid(vector<string> &v,int n)
    {
        int q=0;
        bool check=true;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]=='Q')
                {
                    q++;
                    if(q>n)
                        return 0;
                    int c1=0,c2=0;
                    for(int k=0;k<n;k++)
                    {
                        if(v[i][k]=='Q')
                            c1++;
                    }
                    for(int k=0;k<n;k++)
                    {
                        if(v[k][j]=='Q')
                            c2++;
                    }
                    if(c1>1 or c2>1)
                        return 0;
                    c1=0,c2=0;
                    int k1=i,k2=j;
                    for(int k=0;k<4;k++)
                    {
                        k1=i,k2=j,c1=0;
                        while(k1>=0 and k2>=0 and k1<n and k2<n)
                        {
                            if(v[k1][k2]=='Q')
                                c1++;
                            k1+=dir[k][0];
                            k2+=dir[k][1];
                            if(c1>1)
                                return 0;
                        }
                    }
                    
                    
                }
            }
        }
        return 1;
    }
    void help(vector<string> &v,int i,int x,int n,int c)
    {
        if(isValid(v,n)==0)
            return ;
        if(i==n)
        {
            if(c==n)
                ans.push_back(v);
            return ;
        }
        for(int j=0;j<n;j++)
        {
            v[i][j]='Q';
            help(v,i+1,x+1,n,c+1);
            v[i][j]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string> v;
        for(int i=0;i<n;i++)
        {
            string s;
            for(int j=0;j<n;j++)
                s.push_back('.');
            v.push_back(s);
        }
        help(v,0,0,n,0);
        return ans;
    }
};