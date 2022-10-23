class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        sort(target.begin(),target.end());
        vector<int> odd,even;
        long long res=0,x=0,y=0,req,rem=0;
        for(int i=0;i<n;i++)
        {
            if(target[i]%2)
                odd.push_back(target[i]);
            else
                even.push_back(target[i]);
        }
        int i=0,j=0;
        for(auto &num:nums)
        {
            if(num%2)
            {
                if(num>odd[i])
                {
                    req=num-odd[i];
                    if(x<=req)
                    {
                        req-=x;
                        x=0;
                        res+=req;
                        y+=req;
                    }
                    else
                    {
                        x-=req;
                    }
                }
                else
                {
                    req=odd[i]-num;
                    if(y<=req)
                    {
                        req-=y;
                        y=0;
                        res+=req;
                        x+=req;
                    }
                    else
                    {
                        y-=req;
                    }
                }
                i++;
            }
            else
            {
                if(num>even[j])
                {
                    req=num-even[j];
                    if(x<=req)
                    {
                        req-=x;
                        x=0;
                        res+=req;
                        y+=req;
                    }
                    else
                    {
                        x-=req;
                    }
                }
                else
                {
                    req=even[j]-num;
                    if(y<=req)
                    {
                        req-=y;
                        y=0;
                        res+=req;
                        x+=req;
                    }
                    else
                    {
                        y-=req;
                    }
                }
                j++;
            }
        }
        return res/2;
        
    }
};