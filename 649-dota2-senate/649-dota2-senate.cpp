class Solution {
public:
    string predictPartyVictory(string senate)
    {
        deque<int> R,D,temp,temp2;
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
            while(R.size()>0 or D.size()>0)
            {
                if(D.size()==0)
                {
                    if(temp2.size())
                        temp2.pop_front();
                    else
                        break;
                    temp.push_back(R.front());
                    R.pop_front();
                }
                else if(R.size()==0)
                {
                    if(temp.size())
                        temp.pop_front();
                    else
                        break;
                    temp2.push_back(D.front());
                    D.pop_front();
                }
                else
                {
                    x=R.front(),y=D.front();
                    D.pop_front();
                    R.pop_front();
                    if(x<y)
                    {
                        temp.push_back(x);
                    }
                    else
                    {
                        temp2.push_back(y);
                    }
                        
                }
            }
            R=temp;
            D=temp2;
            temp.clear();
            temp2.clear();
        }
        return D.size()>0 ? "Dire":"Radiant";
    }
};