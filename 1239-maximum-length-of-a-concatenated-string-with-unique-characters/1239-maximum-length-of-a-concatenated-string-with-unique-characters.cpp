class Solution {
public:
    int maxLength(vector<string>& arr,int i=0,int cur=0) 
    {
        if(i==arr.size())
            return 0;
        bool poss=true;
        int x=cur;
        for(char &c:arr[i])
        {
            if((cur&(1<<(c-'a'))) or (x&(1<<(c-'a'))))
            {
                poss=false;
            }
            x|=(1<<(c-'a'));
        }
        if(poss)
            return max(maxLength(arr,i+1,x)+(int)arr[i].length(),maxLength(arr,i+1,cur));
        else
            return maxLength(arr,i+1,cur);
    }
};