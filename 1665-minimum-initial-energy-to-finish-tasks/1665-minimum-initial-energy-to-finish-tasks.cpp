class Solution {
public:
    bool static comp(vector<int> &a,vector<int> &b)
    {
        return a[0]-a[1]<b[0]-b[1];
    }
    bool check(int x,vector<vector<int>>& tasks)
    {
        for(auto &task:tasks)
        {
            if(x<task[1])
                return false;
            x-=task[0];
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),comp);
        int low=1,high=1e9,mid=0,res=0;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(check(mid,tasks))
            {
                res=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return res;
    }
};