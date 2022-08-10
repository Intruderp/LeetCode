class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int,int> freq;
        int x=0,n=arr.size(),res=0,cur,z;
        for(int i=0;i<n;i++)
        {
            x^=arr[i];
            freq[x]++;
        }
        x=0;
        for(int i=0;i<n;i++)
        {
            x^=arr[i];
            z=x;
            cur=arr[i];
            freq[x]--;
            for(int j=i+1;j<n;j++)
            {
                res+=freq[cur^z];
                cur^=arr[j];
                z^=arr[j];
                freq[z]--;
            }
            z=x;
            for(int j=i+1;j<n;j++)
            {
                z^=arr[j];
                freq[z]++;
            }
        }
        return res;
    }
};