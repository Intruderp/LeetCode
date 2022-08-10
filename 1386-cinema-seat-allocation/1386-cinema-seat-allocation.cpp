class Solution {
public:
    int maxNumberOfFamilies(int t, vector<vector<int>>& reservedSeats) 
    {
        sort(reservedSeats.begin(),reservedSeats.end());
        int res=0,curRow=0,n=reservedSeats.size(),i=0,j;
        while(i<n)
        {
            int a=1,b=1,c=1,d=1;
            j=i;
            while(j<n and reservedSeats[j][0]==reservedSeats[i][0])
            {
                if(reservedSeats[j][1]>=2 and reservedSeats[j][1]<=9)
                    a=0;
                if(reservedSeats[j][1]>=2 and reservedSeats[j][1]<=5)
                    b=0;
                if(reservedSeats[j][1]>=4 and reservedSeats[j][1]<=7)
                    c=0;
                if(reservedSeats[j][1]>=6 and reservedSeats[j][1]<=9)
                    d=0;
                j++;
            }
            i=j;
            if(a)
                res+=2;
            else if(b or c or d)
                res++;
        }
        for(int i=0;i<n;i++)
        {
            if(reservedSeats[i][0]>curRow+1)
                res+=(reservedSeats[i][0]-curRow-1)*2;
            curRow=reservedSeats[i][0];
        }
        res+=(t-curRow)*2;
        return res;
    }
};