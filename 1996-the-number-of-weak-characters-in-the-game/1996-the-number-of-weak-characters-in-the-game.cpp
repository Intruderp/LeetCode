class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) 
    {
        int weakCharacters=0,n=properties.size(),maxDefense=0;
        sort(properties.begin(),properties.end(),comp);
        for(int i=n-2;i>=0;i--)
        {
            if(properties[i+1][0]!=properties[i][0])
                maxDefense=max(maxDefense,properties[i+1][1]);
            if(maxDefense>properties[i][1])
                weakCharacters++;
        }
        return weakCharacters;
    }
};