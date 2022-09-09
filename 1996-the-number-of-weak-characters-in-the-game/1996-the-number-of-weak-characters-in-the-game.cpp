class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) 
    {
        int weakCharacters=0,n=properties.size(),maxDefense=0;
        for(auto &property:properties)
            property[1]*=-1;
        sort(properties.begin(),properties.end());
        for(int i=n-1;i>=0;i--)
        {
            maxDefense=max(maxDefense,-properties[i][1]);
            if(maxDefense>-properties[i][1])
                weakCharacters++;
        }
        return weakCharacters;
    }
};