class Solution {
public:
    void help(int n,int p,int &k,int num,vector<int> &res)
    {
        if(n==0)
        {
            res.push_back(num);
            return ;
        }
        int x=p+k,y=p-k;
        if(x>=0 and x<=9)
        {
            help(n-1,x,k,num*10+x,res);
        }
        if(y>=0 and y<=9 and x!=y)
        {
            help(n-1,y,k,num*10+y,res);
        }
        
    }
    vector<int> numsSameConsecDiff(int n, int k) 
    {
        vector<int> res;
        for(int i=1;i<10;i++)
        {
            help(n-1,i,k,i,res);
        }
        return res;
    }
};