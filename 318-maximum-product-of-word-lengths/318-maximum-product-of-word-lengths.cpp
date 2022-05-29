class Solution {
public:
    int maxProduct(vector<string>& words) 
    {
        int ans=0,n=words.size();
        vector<int> v(n);
        int mask=0;
        bool poss;
        for(int i=0;i<n;i++)
        {
            mask=0;
            for(char &c:words[i])
            {
                mask|=(1<<(c-'a'));
            }
            v[i]=mask;
            for(int j=0;j<i;j++)
            {
                int len=words[i].length()*words[j].length();
                if((v[i]&v[j])==0)
                    ans=max(ans,len);
            }
        }
        return ans;
    }
};