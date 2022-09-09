class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids)
    {
        for(auto &cuboid:cuboids)
        {
            sort(cuboid.begin(),cuboid.end());
        }
        int n=cuboids.size();
        sort(cuboids.begin(),cuboids.end());
        vector<int> dp(n,0);
        for(int i=0;i<n;i++)
            dp[i]=cuboids[i][2];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(cuboids[j][1]<=cuboids[i][1] and cuboids[j][2]<=cuboids[i][2])
                    dp[i]=max(dp[i],dp[j]+cuboids[i][2]);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};