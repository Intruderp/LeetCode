class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long res=0;
        horizontalCuts.push_back(0);
        verticalCuts.push_back(0);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        int maxV=0,n=horizontalCuts.size(),m=verticalCuts.size();
        for(int i=0;i<m-1;i++)
        {
            maxV=max(maxV,verticalCuts[i+1]-verticalCuts[i]);
        }
        for(int i=0;i+1<n;i++)
        {
            res=max(res,(long long)(maxV)*(horizontalCuts[i+1]-horizontalCuts[i]));
        }
        return res%1000000007;
    }
};