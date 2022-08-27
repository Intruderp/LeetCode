class Solution {
public:
    void help(int num,int &n,vector<int> &res)
    {
        if(num>n)
            return ;
        res.push_back(num);
        for(int i=0;i<=9;i++)
        {
            help(num*10+i,n,res);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i=1;i<=min(9,n);i++)
            help(i,n,res);
        return res;
    }
};