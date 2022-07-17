class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        long long x;
        int n=spells.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            x=(success+spells[i]-1)/spells[i];
            ans[i]=(potions.end()-lower_bound(potions.begin(),potions.end(),x));
        }
        return ans;
    }
};