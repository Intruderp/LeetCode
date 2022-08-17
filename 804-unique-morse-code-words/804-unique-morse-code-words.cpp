class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> map{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        string transformation;
        for(auto &word:words)
        {
            for(char &c:word)
                transformation+=map[c-'a'];
            s.insert(transformation);
            transformation.clear();
        }
        return s.size();
    }
};