class Solution {
public:
    vector<int> res;
    bool dfs(int cur,int mul,int level,int label)
    {
        if(cur==label)
        {
            res.push_back(cur);
            return true;
        }
        if(cur>label)
            return false;
        res.push_back(cur);
        int posn=cur-mul+1,child=mul*2*2-1-(posn-1)*2,x=-1;
        if(level%2)
        {
            posn=mul*2-cur;
            child=mul*2+(posn-1)*2;
            x=1;
        }
        if(dfs(child,mul*2,level+1,label))
            return true;
        if(dfs(child+x,mul*2,level+1,label))
            return true;
        res.pop_back();
        return false;
    }
    vector<int> pathInZigZagTree(int label) {
        dfs(1,1,0,label);
        return res;
    }
};