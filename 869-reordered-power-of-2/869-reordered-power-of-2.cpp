class Solution {
public:
    bool reorderedPowerOf2(int n) 
    {
        int p=1;
        vector<int> cnt(10,0);
        while(n)
        {
            cnt[n%10]++;
            n/=10;
        }
        while(p<=1000000000)
        {
            vector<int> cur(10,0);
            int x=p;
            while(x)
            {
                cur[x%10]++;
                x/=10;
            }
            bool poss=true;
            for(int i=0;i<=9;i++)
            {
                if(cnt[i]!=cur[i])
                {
                    poss=false;
                    break;
                }
            }
            if(poss)
                return true;
            p*=2;
        }
        return false;
    }
};