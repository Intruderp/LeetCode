class Solution {
public:
    bool help(int bit,int cur,int k,int &max,int &n,vector<int> &cookies)
    {
        if(bit==(1<<n)-1)
            return true;
        bool ans=false;
        for(int i=0;i<n;i++)
        {
            if((bit&(1<<i))==0)
            {
                if(cur+cookies[i]<=max)
                    ans|=help(bit|(1<<i),cur+cookies[i],k,max,n,cookies);
                else if(k>1)
                    ans|=help(bit|(1<<i),cookies[i],k-1,max,n,cookies);
            }
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) 
    {
        int n=cookies.size();
        int low=*max_element(cookies.begin(),cookies.end()),high=accumulate(cookies.begin(),cookies.end(),0),mid,poss=-1;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(help(0,0,k,mid,n,cookies))
            {
                poss=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return poss;
    }
};