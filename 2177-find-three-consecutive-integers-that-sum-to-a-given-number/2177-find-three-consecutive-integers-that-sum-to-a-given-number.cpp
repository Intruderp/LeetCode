class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        num-=3;
        if(num%3)
            return vector<long long>{};
        return vector<long long>{num/3,num/3+1,num/3+2};
    }
};