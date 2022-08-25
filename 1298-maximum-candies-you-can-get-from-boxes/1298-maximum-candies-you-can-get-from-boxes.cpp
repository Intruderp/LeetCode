class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) 
    {
        int n=status.size(),res=0;
        vector<int> available(n,0);
        queue<int> q;
        unordered_set<int> s;
        for(auto &box:initialBoxes)
        {
            if(status[box]==0)
            {
                s.insert(box);
                continue;
            }
            available[box]=1;
            q.push(box);
        }
        while(!q.empty())
        {
            int f=q.front();
            q.pop();
            for(auto &box:keys[f])
            {
                status[box]=1;
                if(s.count(box))
                {
                    available[box]=1;
                    q.push(box);
                    s.erase(box);
                }
            }
            for(auto &box:containedBoxes[f])
            {
                if(available[box]==0)
                {
                   if(status[box])
                   {
                        available[box]=1;
                        q.push(box);
                   }
                    else
                    {
                        s.insert(box);
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(available[i])
                res+=candies[i];
        }
        return res;
    }
};