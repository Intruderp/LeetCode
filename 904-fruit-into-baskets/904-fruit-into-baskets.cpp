class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size(),i=0,j=0,res=0;
        unordered_map<int,int> m;
        while(j<n)
        {
            while(j<n and m.size()<=2)
            {
                if(m.size()==2 and m.count(fruits[j])==0)
                    break;
                m[fruits[j]]++;
                j++;
            }
            res=max(res,j-i);
            m[fruits[i]]--;
            if(m[fruits[i]]==0)
                m.erase(fruits[i]);
            i++;
        }
        return res;
    }
};