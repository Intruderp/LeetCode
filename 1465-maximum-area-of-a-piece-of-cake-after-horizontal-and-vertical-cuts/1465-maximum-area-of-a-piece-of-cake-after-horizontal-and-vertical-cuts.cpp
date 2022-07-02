class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        verticalCuts.push_back(0);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        int maxV=0,maxH=0,n=horizontalCuts.size(),m=verticalCuts.size();
        for(int i=0;i<m-1;i++)
        {
            maxV=max(maxV,verticalCuts[i+1]-verticalCuts[i]);
        }
        for(int i=0;i+1<n;i++)
        {
            maxH=max(maxH,horizontalCuts[i+1]-horizontalCuts[i]);
        }
        long long res=(long long)maxH*maxV;
        return res%1000000007;
    }
};