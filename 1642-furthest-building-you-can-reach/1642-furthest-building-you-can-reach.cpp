class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        long long sum=0;
        priority_queue<int> q;
        int n=heights.size(),i=1,diff;
        for(;i<n;i++)
        {
            diff=heights[i]-heights[i-1];
            if(diff>0)
            {
                if(q.size()<ladders)
                    q.push(-diff);
                else
                {
                    if(q.size()==0)
                    {
                        if(diff>bricks)
                            break;
                        bricks-=diff;
                    }
                    else if(q.top()*(-1)<diff)
                    {
                        bricks-=(q.top()*(-1));
                        if(bricks<0)
                            break;
                        q.pop();
                        q.push(-diff);
                    }
                    else
                    {
                        if(diff>bricks)
                            break;
                        bricks-=diff;
                    }
                }
                    
            }
        }
        return i-1;
    }
};