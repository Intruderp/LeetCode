class Solution {
public:
    int count(int i,vector<vector<int>> &mat,int &reqSum,int sum,int &k)
    {
        if(sum>reqSum)
            return 0;
        if(i==mat.size())
            return 1;
        int cnt=0;
        for(int &num:mat[i])
        {
            int poss=count(i+1,mat,reqSum,sum+num,k);
            if(poss==0)
                break;
            cnt+=poss;
            if(cnt>=k)
                break;
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& mat, int k) 
    {
        int n=mat.size(),low=n,high=n*5000,mid,res=0;
        while(low<=high)
        {
            mid=(high+low)/2;
            if(count(0,mat,mid,0,k)>=k)
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