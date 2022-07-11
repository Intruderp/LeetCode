class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int mx=*max_element(labels.begin(),labels.end()),res=0,n=values.size();
        vector<int> v(mx+1,0);
        priority_queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
            q.push({values[i],labels[i]});
        while(!q.empty() and numWanted)
        {
            auto t=q.top();
            q.pop();
            if(v[t.second]<useLimit)
            {
                v[t.second]++;
                res+=t.first;
                numWanted--;
            }
        }
        return res;
    }
};