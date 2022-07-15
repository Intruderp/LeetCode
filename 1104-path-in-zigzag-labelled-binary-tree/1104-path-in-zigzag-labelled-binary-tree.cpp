class Solution {
public:
    vector<int> pathInZigZagTree(int label)
    {
        vector<int> res;
        res.push_back(label);
        int height=log2(label),p=pow(2,height),posn,par;
        while(res.back()!=1)
        {
            posn=(res.back()-p+2)/2;
            if(height%2)
                posn=(p*2-res.back()+1)/2;
            p/=2;
            height--;
            par=p+posn-1;
            if(height%2)
                par=p*2-posn;
            res.push_back(par);
            
        }
        reverse(res.begin(),res.end());
        return res;
    }
};