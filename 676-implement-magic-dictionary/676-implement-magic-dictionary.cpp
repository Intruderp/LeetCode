class MagicDictionary {
public:
    unordered_set<string> s;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto &word:dictionary)
            s.insert(word);
    }
    
    bool search(string searchWord) {
        int n=searchWord.length();
        for(int i=0;i<n;i++)
        {
            char c=searchWord[i];
            for(char x='a';x<='z';x++)
            {
                if(x==c)
                    continue;
                searchWord[i]=x;
                if(s.count(searchWord))
                    return true;
            }
            searchWord[i]=c;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */