class Solution {
public:
    vector<vector<int>> permutations;
    vector<int> v;
    Solution(vector<int>& nums) {
        v=nums;
        sort(nums.begin(),nums.end());
        do{
            permutations.push_back(nums);
            if(permutations.size()==10000)
                break;
        }while(next_permutation(nums.begin(),nums.end()));
    }
    
    vector<int> reset() {
        return v;
    }
    
    vector<int> shuffle() {
        return permutations[rand()%permutations.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */