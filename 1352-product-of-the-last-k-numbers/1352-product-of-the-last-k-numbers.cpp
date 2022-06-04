class ProductOfNumbers {
public:
    int n,p=-1;
    vector<int> v;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0)
        {
            p=v.size();
            v.push_back(0);
        }
        else
        {
            if(v.size()==0 or v.back()==0)
                v.push_back(num);
            else
                v.push_back(v.back()*num);
        }
        
    }
    
    int getProduct(int k) {
        int x=v.size()-k;
        if(x<=p)
            return 0;
        int d=1;
        if(x>0 and v[x-1]!=0)
            d=v[x-1];
        return v.back()/d;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */