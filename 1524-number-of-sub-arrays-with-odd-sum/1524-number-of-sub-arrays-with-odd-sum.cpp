class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        unordered_map<int,int> m;
        m[0]=1;
        int ans=0,mod=1e9+7,cur=0;
        for(int &num:arr)
        {
            cur=(cur+num)%2;
            if(m.count((cur+1)%2))
                ans=(ans+m[(cur+1)%2])%mod;
            m[cur]++;
        }
        return ans;
    }
};