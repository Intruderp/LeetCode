class ATM {
    vector<long> cnt,val;
    bool poss(int amount,vector<int> &res)
    {
        int i=4;
        while(amount and i>=0)
        {
            long cur=(long)val[i]*cnt[i];
            if(cur<=amount)
            {
                amount-=cur;
                res[i]+=cnt[i];
            }
            else
            {
                int req=amount/val[i];
                amount-=req*val[i];
                res[i]+=req;
            }
            i--;
        }
        if(amount==0)
            return true;
        return false;
    }
public:
    ATM() 
    {
        cnt.resize(5,0);
        val={20,50,100,200,500};
    }
    void deposit(vector<int> banknotesCount) 
    {
        for(int i=0;i<5;i++)
        {
            cnt[i]+=banknotesCount[i];
        }
    }
    vector<int> withdraw(int amount)
    {
        vector<int> res(5,0);
        if(poss(amount,res))
        {
            for(int i=0;i<5;i++)
                cnt[i]-=res[i];
            return res;
        }
        else
            return vector<int>{-1};
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */