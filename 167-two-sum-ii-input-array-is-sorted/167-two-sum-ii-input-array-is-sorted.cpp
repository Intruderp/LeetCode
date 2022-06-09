class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int l=0,r=numbers.size()-1;
        while(numbers[l]+numbers[r]!=target)
        {
            if(numbers[l]+numbers[r]>target)
                r--;
            else
                l++;
        }
        vector<int> ans{l+1,r+1};
        return ans;
    }
};