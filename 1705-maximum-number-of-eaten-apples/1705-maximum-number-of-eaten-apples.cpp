class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) 
    {
        int cnt=0,day=1,n=apples.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(int i=0;i<n;i++)
        {
            if(apples[i])
                q.push({i+days[i],i});
            while(!q.empty() and day>q.top().first)
                q.pop();
            if(q.size())
            {
                auto temp=q.top();
                if(apples[temp.second]>1)
                    apples[temp.second]--;
                else
                    q.pop();
                cnt++;
            }
            day++;
        }
        while(q.size())
        {
            while(!q.empty() and day>q.top().first)
                q.pop();
            if(q.empty())
                break;
            cnt++;
            day++;
            auto temp=q.top();
            if(apples[temp.second]>1)
                apples[temp.second]--;
            else
                q.pop();
        }
        return cnt;
    }
};