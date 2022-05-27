class Solution {
public:
    int numberOfSteps(int num) {
        if(!num)
            return 0;
        int count=0;
        while(num)
        {
            if(num%2)
                count++;
            num/=2;
            count++;
        }
        return count-1;
    }
};