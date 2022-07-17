class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> passengers(1001,0);
        for(auto &trip:trips)
        {
            passengers[trip[1]]+=trip[0];
            passengers[trip[2]]-=trip[0];
        }
        int cur=0;
        for(int i=0;i<=1000;i++)
        {
            cur+=passengers[i];
            if(cur>capacity)
                return false;
        }
        return true;
    }
};