class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end(),comp);
        int prev=-1,prev2=-1;
        int req=0,minSize=0;
        for(auto &interval:intervals)
        {
            req=2;
            if(prev==-1)
            {
                prev=interval[1]-1;
                prev2=interval[1];
            }
            else
            {
                if(prev>=interval[0])
                    req--;
                if(prev2>=interval[0])
                    req--;
            }
            if(req==1)
            {
                prev=prev2;
                if(prev2!=interval[1])
                    prev2=interval[1];
                else
                    prev2=interval[1]-1;
            }
            else if(req==2)
            {
                prev=interval[1]-1;
                prev2=interval[1];
            }
             minSize+=req;
        }
        return minSize;
    }
};