class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        n=foods.size();
        for(int i=0;i<n;i++)
        {
            m[cuisines[i]].insert({-ratings[i],foods[i]});
            cuisine[foods[i]]=cuisines[i];
            rating[foods[i]]=ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) 
    {
        if(rating[food]!=newRating)
        {
            m[cuisine[food]].erase({-rating[food],food});
            rating[food]=newRating;
            m[cuisine[food]].insert({-rating[food],food});
        }
    }
    
    string highestRated(string cuisine) {
        return m[cuisine].begin()->second;
    }
private:
    unordered_map<string,set<pair<int,string>>> m;
    unordered_map<string,int> rating;
    unordered_map<string,string> cuisine;
    int n;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */