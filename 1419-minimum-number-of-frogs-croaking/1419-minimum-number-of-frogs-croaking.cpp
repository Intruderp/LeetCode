class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) 
    {
        int cnt[5]={0},res=0,cur=0;
        for(char &c:croakOfFrogs)
        {
            if(c=='c')
            {
                cnt[0]++;
                cur++;
            }
            else if(c=='r')
            {
                cnt[1]++;
                if(cnt[1]>cnt[0])
                    return -1;
            }
            else if(c=='o')
            {
                cnt[2]++;
                if(cnt[2]>min(cnt[0],cnt[1]))
                    return -1;
            }
            else if(c=='a')
            {
                cnt[3]++;
                if(cnt[3]>min({cnt[0],cnt[1],cnt[2]}))
                    return -1;
            }
            else
            {
                cnt[4]++;
                if(cnt[4]>min({cnt[0],cnt[1],cnt[2],cnt[4]}))
                    return -1;
                cur--;
            }
            res=max(res,cur);
        }
        sort(cnt,cnt+5);
        return cnt[0]==cnt[4] ? res:-1;
    }
};