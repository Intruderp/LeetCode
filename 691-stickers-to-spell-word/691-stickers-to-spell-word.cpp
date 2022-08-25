class Solution {
public:
    int n,m,dp[50][1<<15];
    int help(int i,int mask,string &target,vector<string> &stickers)
    {
        if(mask==(1<<m)-1)
            return 0;
        if(i==n)
            return 1000;
        if(dp[i][mask]!=-1)
            return dp[i][mask];
        int newMask=mask;
        vector<int> cnt(26,0);
        for(char &c:stickers[i])
            cnt[c-'a']++;
        for(int j=0;j<m;j++)
        {
            if((newMask&(1<<j))==0 and cnt[target[j]-'a'])
            {
                newMask|=(1<<j);
                cnt[target[j]-'a']--;
            }
        }
        if(newMask!=mask)
            return dp[i][mask]=min(help(i,newMask,target,stickers)+1,help(i+1,mask,target,stickers));
        else
            return dp[i][mask]=help(i+1,mask,target,stickers);
    }
    int minStickers(vector<string>& stickers, string target)
    {
        n=stickers.size();
        m=target.length();
        memset(dp,-1,sizeof(dp));
        int res=help(0,0,target,stickers);
        return res<1000 ? res:-1;
    }
};