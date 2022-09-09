class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) 
    {
        int i=0,cur=0,n=clips.size(),res=0;
        sort(clips.begin(),clips.end());
        while(cur<time)
        {
            int maxi=cur;
            while(i<n and clips[i][0]<=cur)
            {
                maxi=max(maxi,clips[i][1]);
                i++;
            }
            if(maxi==cur)
                return -1;
            res++;
            cur=maxi;   
        }
        return res;
    }
};