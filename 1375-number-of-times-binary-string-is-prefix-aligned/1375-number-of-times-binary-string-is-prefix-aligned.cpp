class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int res=0,lastOne=0,n=flips.size(),steps=0;
        for(auto &flip:flips)
        {
            steps++;
            lastOne=max(flip,lastOne);
            if(lastOne==steps)
                res++;
        }
        return res;
    }
};