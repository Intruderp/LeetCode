class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) 
    {
        int weakCharacters=0,n=properties.size(),maxDefense=0;
        for(auto &property:properties)
            property[1]*=-1;
        sort(properties.begin(),properties.end());
        for(int i=n-2;i>=0;i--)
        {
            if(properties[i+1][0]!=properties[i][0])
                maxDefense=max(maxDefense,-properties[i+1][1]);
            if(maxDefense>-properties[i][1])
                weakCharacters++;
        }
        return weakCharacters;
    }
};