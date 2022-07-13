class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n=aliceValues.size();
        vector<pair<int,int>> scores(n);
        for(int i=0;i<n;i++)
            scores[i]={aliceValues[i]+bobValues[i],i};
        int alice=0,bob=0,i=0,turn=1;
        sort(scores.rbegin(),scores.rend());
        while(i<n)
        {
            if(turn)
                alice+=aliceValues[scores[i].second];
            else
                bob+=bobValues[scores[i].second];
            i++;
            turn^=1;
        }
        if(bob==alice)
            return 0;
        return bob<alice ? 1:-1;
    }
};