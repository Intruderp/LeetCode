class Solution {
public:
    bool hasAllCodes(string s, int k) 
    {
        int n=s.length(),j,num,m;
        vector<int> count((1<<k),0);
        for(int i=0;i<n-k+1;i++)
        {
            m=1;
            num=0;
            j=i+k-1;
            while(j>=i)
            {
                if(s[j]=='1')
                    num+=m;
                m*=2;
                j--;
            }
            count[num]=1;
        }
        for(int &num:count)
        {
            if(!num)
                return false;
        }
        return true;
    }
};