class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int res=0;
        for(auto &box:boxTypes)
        {
            res+=min(truckSize,box[0])*box[1];
            truckSize-=box[0];
            if(truckSize<=0)
                break;
        }
        return res;
    }
};