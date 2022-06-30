class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.length(),res=0,x,y,sz,sz2;
        vector<int> t,f;
        for(int i=n-1;i>=0;i--)
        {
            if(answerKey[i]=='T')
                t.push_back(i);
            else
                f.push_back(i);
        }
        for(int i=0;i<n;i++)
        {
            sz=t.size();
            sz2=f.size();
            if(sz-k-1<0)
                res=max(res,n-i);
            else
                res=max(res,t[sz-k-1]-i);
            if(sz2-k-1<0)
                res=max(res,n-i);
            else
                res=max(res,f[sz2-k-1]-i);
            if(t.size() and t.back()<=i)
                t.pop_back();
            if(f.size() and f.back()<=i)
                f.pop_back();
            
        }
        return res;
    }
};