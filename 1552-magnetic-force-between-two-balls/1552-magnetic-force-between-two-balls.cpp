class Solution {
public:
    bool possible(int &minDist,int m,vector<int> &position)
    {
        int prev=0,n=position.size();
        m--;
        for(int i=1;i<n;i++)
        {
            if(position[i]-position[prev]>=minDist)
            {
                m--;
                prev=i;
                if(m==0)
                    return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) 
    {
        sort(position.begin(),position.end());
        int low=1,high=1e9,mid,res;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(possible(mid,m,position))
            {
                res=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return res;
    }
};