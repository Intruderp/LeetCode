class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> q;
        int n;
        if(a)
            q.push({a,'a'});
        if(b)
            q.push({b,'b'});
        if(c)
            q.push({c,'c'});
        string res;
        while(!q.empty())
        {
            n=res.length();
            auto t=q.top();
            q.pop();
            if(n<2 or res[n-1]!=res[n-2] or res[n-1]!=t.second)
            {
                res.push_back(t.second);
                if(t.first>1)
                    q.push({t.first-1,t.second});
            }
            else
            {
                if(q.empty())
                    break;
                auto t2=q.top();
                q.pop();
                res.push_back(t2.second);
                if(t2.first>1)
                    q.push({t2.first-1,t2.second});
                q.push(t);
            }
        }
        return res;
    }
    
};