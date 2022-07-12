class Solution {
public:
    int sideLen=0,n;
    bool poss(int i,int x,vector<int> &v)
    {
        if(x>sideLen)
            return false;
        if(i==v.size())
            return x==sideLen;
        return poss(i+1,x+v[i],v) or poss(i+1,x,v);
    }
    bool help(int i,int a,int b,int bit,vector<int> &v)
    {
        if(max(a,b)>2*sideLen)
            return false;
        if(i==v.size())
        {
            vector<int> p,p2;
            for(int i=0;i<n;i++)
            {
                if(((1<<i)&bit))
                    p.push_back(v[i]);
                else
                    p2.push_back(v[i]);
            }
            return poss(0,0,p) and poss(0,0,p2);
        }
        return help(i+1,a+v[i],b,bit|(1<<i),v) or help(i+1,a,b+v[i],bit,v);
    }
    bool makesquare(vector<int>& m) 
    {
        int sum=accumulate(m.begin(),m.end(),0);
        if(sum%4)
            return false;
        sideLen=sum/4;
        n=m.size();
        return help(0,0,0,0,m);
    }
};