class Solution {
public:
    void help(int n,int p,int &k,int num,int m,vector<int> &res)
    {
        if(n==0)
        {
            res.push_back(num);
            return ;
        }
        int x=p+k,y=p-k;
        if(x>=0 and x<=9)
        {
            if(n!=1 or x!=0)
                help(n-1,x,k,num+x*m,m*10,res);
        }
        if(y>=0 and y<=9 and x!=y)
        {
            if(n!=1 or y!=0)
                help(n-1,y,k,num+y*m,m*10,res);
        }
        
    }
    vector<int> numsSameConsecDiff(int n, int k) 
    {
        vector<int> res;
        for(int i=0;i<10;i++)
        {
            help(n-1,i,k,i,10,res);
        }
        return res;
    }
};