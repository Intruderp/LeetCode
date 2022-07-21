class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum=0,sum2=0,d,res=0,i=0,j=5,a;
        vector<int> v(6,0),v2(6,0);
        for(auto &x:nums1)
        {
            sum+=x;
            v[x-1]++;
        }
        for(auto &x:nums2)
        {
            sum2+=x;
            v2[x-1]++;
        }
        if(sum>sum2)
        {
            swap(sum,sum2);
            swap(v,v2);
        }
        while(sum!=sum2 and i<5 and j>0)
        {
            d=sum2-sum;
            if((6-i-1)>j)
            {
                a=(6-i-1)*v[i];
                if(d>a)
                {
                    sum+=a;
                    res+=v[i];
                }
                else
                {
                    sum=sum2;
                    res+=(d+6-i-2)/(6-i-1);
                }
                i++;
            }
            else
            {
                a=j*v2[j];
                if(d>a)
                {
                    sum2-=a;
                    res+=v2[j];
                }
                else
                {
                    sum2=sum;
                    res+=(d+j-1)/j;
                }
                j--;
            }
                
        }
        while(sum!=sum2 and j>0)
        {
            a=j*v2[j];
            if(d>a)
            {
                sum2-=a;
                res+=v2[j];
            }
            else
            {
                sum2=sum;
                res+=(d+j-1)/j;
            }
            j--;
        }
        while(sum!=sum2 and i<5)
        {
            a=(6-i-1)*v[i];
            if(d>a)
            {
                sum+=a;
                res+=v[i];
            }
            else
            {
                sum=sum2;
                res+=(d+6-i-2)/(6-i-1);
            }
            i++;
        }
        return sum==sum2 ? res:-1;
    }
};