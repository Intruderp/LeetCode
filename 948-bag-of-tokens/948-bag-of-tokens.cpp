class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
        sort(tokens.rbegin(),tokens.rend());
        int n=tokens.size(),i=0,j=n-1,maxScore=0,curScore=0;
        while(j>=i)
        {
            if(power>=tokens[j])
            {
                curScore++;
                maxScore=max(maxScore,curScore);
                power-=tokens[j];
                j--;
            }
            else if(curScore>0)
            {
                curScore--;
                power+=tokens[i];
                i++;
            }
            else
                break;
        }
        return maxScore;
    }
};