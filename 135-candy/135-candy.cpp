class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size(),res=0;
        vector<int> v(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(int i=0;i<n;i++)
            q.push({ratings[i],i});
        while(q.size())
        {
            auto t=q.top();
            q.pop();
            int x=1,i=t.second;
            if(i-1>=0 and ratings[i-1]<ratings[i])
                x=v[i-1]+1;
            if(i+1<n and ratings[i+1]<ratings[i])
                x=max(x,v[i+1]+1);
            v[i]=x;
            res+=x;
        }
        return res;
    }
};