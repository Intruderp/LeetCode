class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int res=0,lastOne=0,n=flips.size(),steps=0;
        set<int> zero;
        for(int i=1;i<=n;i++)
            zero.insert(i);
        for(auto &flip:flips)
        {
            steps++;
            if(steps==n)
                break;
            lastOne=max(flip,lastOne);
            zero.erase(flip);
            if(lastOne==steps and *zero.begin()==steps+1)
                res++;
        }
        return res+1;
    }
};