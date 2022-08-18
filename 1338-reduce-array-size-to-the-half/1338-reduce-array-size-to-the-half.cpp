class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int req=arr.size()/2,res=INT_MAX;
        unordered_map<int,int> freq;
        for(auto &num:arr)
            freq[num]++;
        priority_queue<int,vector<int>,greater<int>> q;
        for(auto &it:freq)
        {
            req-=it.second;
            q.push(it.second);
            while(req+q.top()<=0)
            {
                req+=q.top();
                q.pop();
            }
            if(req<=0)
                res=min(res,(int)q.size());
        }
        return res;
    }
};