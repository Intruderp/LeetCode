class Solution {
public:
    string reorganizeString(string s) {
        int freq[26]={0},n=s.length(),mx=0;
        for(char &c:s)
        {
            freq[c-'a']++;
            mx=max(mx,freq[c-'a']);
        }
        if(mx>(n+1)/2)
            return "";
        string res;
        priority_queue<pair<int,char>> q;
        for(int i=0;i<26;i++)
        {
            if(freq[i])
                q.push({freq[i],'a'+i});
        }
        while(!q.empty())
        {
            auto t=q.top();
            q.pop();
            if(res.length()==0 or res.back()!=t.second)
            {
                res.push_back(t.second);
                if(t.first>1)
                    q.push({t.first-1,t.second});
            }
            else
            {
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