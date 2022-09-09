class Solution {
public:
    int dp[100][101];
    int help(int i,int cur,int &time,vector<vector<int>> &clips)
    {
        if(cur>=time)
            return 0;
        if(i==clips.size())
            return 10000;
        if(dp[i][cur]!=-1)
            return dp[i][cur];
        if(clips[i][0]<=cur)
            return dp[i][cur]=min(help(i+1,max(cur,clips[i][1]),time,clips)+1,help(i+1,cur,time,clips));
        else
            return dp[i][cur]=10000;
        
    }
    int videoStitching(vector<vector<int>>& clips, int time) 
    {
        sort(clips.begin(),clips.end());
        memset(dp,-1,sizeof(dp));
        int minClips=help(0,0,time,clips);
        return minClips<=100 ? minClips:-1;
    }
};