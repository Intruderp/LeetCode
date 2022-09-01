class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) 
    {
        int res=INT_MAX;
        unordered_map<int,unordered_set<int>> lang;
        unordered_set<int> canCommunicate;
        for(int i=0;i<languages.size();i++)
        {
            for(auto &language:languages[i])
                lang[i].insert(language);
        }
        for(int i=0;i<friendships.size();i++)
        {
            for(auto &language:languages[friendships[i][0]-1])
            {
                if(lang[friendships[i][1]-1].count(language))
                {
                    canCommunicate.insert(i);
                    break;
                }
            }
        }
        for(int l=1;l<=n;l++)
        {
            unordered_set<int> req;
            for(int i=0;i<friendships.size();i++)
            {
                if(canCommunicate.count(i))
                    continue;
                if(lang[friendships[i][0]-1].count(l)==0)
                    req.insert(friendships[i][0]);
                if(lang[friendships[i][1]-1].count(l)==0)
                    req.insert(friendships[i][1]);
            }
            res=min(res,(int)req.size());
        }
        return res;
    }
};