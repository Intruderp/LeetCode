class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters)
    {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int j=0,n=heaters.size(),x,res=0;
        for(auto &house:houses)
        {
            while(j+1<n and heaters[j]<house)
                j++;
            x=abs(house-heaters[j]);
            if(j>0)
                x=min(x,abs(house-heaters[j-1]));
            res=max(res,x);
        }
        return res;
    }
};