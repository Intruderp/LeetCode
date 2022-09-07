class Solution {
public:
    int longestWPI(vector<int>& hours) 
    {
        int n=hours.size(),res=0,cur=0;
        unordered_map<int,int> pre;
        for(int i=0;i<n;i++)
        {
            cur+=hours[i]>8 ? 1:-1;
            if(cur>0)
                res=i+1;
            else
            {
                if(pre.count(cur-1))
                    res=max(res,i-pre[cur-1]);
                if(pre.count(cur)==0)
                    pre[cur]=i;
            }
        }
        return res;
    }
};