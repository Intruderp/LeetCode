class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int,int> freq,m;
        freq[0]=1;
        m[0]=-1;
        int n=arr.size(),res=0,x=0;
        for(int i=0;i<n;i++)
        {
            x^=arr[i];
            res+=freq[x]*(i-1)-m[x];
            freq[x]++;
            m[x]+=i;
        }
        return res;
    }
};