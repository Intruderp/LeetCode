class Solution {
public:
    string predictPartyVictory(string senate)
    {
        deque<int> R,D;
        int n=senate.length(),x,y;
        for(int i=0;i<n;i++)
        {
            if(senate[i]=='D')
                D.push_back(i);
            else
                R.push_back(i);
        }
        while(R.size()>0 and D.size()>0)
        {
            x=R.front();
            y=D.front();
            R.pop_front();
            D.pop_front();
            if(x<y)
                R.push_back(x+n);
            else
                D.push_back(y+n);
                
        }
        return D.size()>0 ? "Dire":"Radiant";
    }
};