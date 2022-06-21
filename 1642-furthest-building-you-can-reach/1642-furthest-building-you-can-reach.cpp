class Solution {
public:
    bool check(vector<int> &heights,int bricks,int ladders,int x)
    {
        priority_queue<int> q;
        for(int i=1;i<=x;i++)
        {
            if(heights[i]>heights[i-1])
            {
                q.push(heights[i]-heights[i-1]);
            }
        }
        while(q.size())
        {
            if(ladders)
                ladders--;
            else
                bricks-=q.top();
            q.pop();
            if(bricks<0)
                return false;
        }
        return true;
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size(),low=1,mid,high=n-1,ans=0;
        while(low<=high)
        {
            mid=(high+low)/2;
            if(check(heights,bricks,ladders,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
    }
};