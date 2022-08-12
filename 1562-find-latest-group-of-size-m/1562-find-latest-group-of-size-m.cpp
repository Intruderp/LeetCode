class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        set<pair<int,int>> s;
        int cnt=0,res=-1,n=arr.size(),x,y;
        s.insert({arr[0],arr[0]});
        if(m==1)
        {
            res=1;
            cnt=1;
        }
        for(int i=1;i<n;i++)
        {
            pair<int,int> p={arr[i],i};
            auto it=s.lower_bound(p);
            if(it==s.end())
            {
                it--;
                if(arr[i]-1==it->second)
                {
                    x=it->first;
                    y=arr[i];
                    cnt+=(y-x+1)==m;
                    cnt-=(it->second-it->first+1)==m;
                    s.erase(it);
                    s.insert({x,y});
                }
                else
                {
                    cnt+=m==1;
                    s.insert({arr[i],arr[i]});
                }
            }
            else
            {
                int a=-1,b=-1;
                x=arr[i];
                y=arr[i];
                if(it->first-1==arr[i])
                {
                    a=it->first;
                    b=it->second;
                    y=b;
                }
                if(it!=s.begin())
                {
                    it--;
                    if(arr[i]-1==it->second)
                    {
                        x=it->first;
                        cnt-=(it->second-it->first+1)==m;
                        s.erase(it);
                    }
                }
                if(a!=-1)
                {
                    cnt-=(b-a+1)==m;
                    s.erase({a,b});
                }
                cnt+=(y-x+1)==m;
                s.insert({x,y});
            }
            if(cnt)
                res=i+1;
        }
        return res;
    }
};