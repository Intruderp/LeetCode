class Solution {
public:
    int trailingZeroes(int n) {
        int cnt2=0,cnt5=0;
        for(int i=2;i<=n;i++)
        {
            int temp=i;
            for(int j=2;j*j<=temp;j++)
            {
              while(temp%j==0)
              {
                  temp/=j;
                  cnt2+=j==2;
                  cnt5+=j==5;
              }
            }
            cnt2+=temp==2;
            cnt5+=temp==5;
        }
        return min(cnt2,cnt5);
    }
};