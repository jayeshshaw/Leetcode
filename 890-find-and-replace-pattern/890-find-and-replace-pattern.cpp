class Solution {
public:
     vector<string> findAndReplacePattern(vector<string> words, string p) {
        vector<string> ans;
        p=normalize(p);
         for(auto i: words){
             if(normalize(i)==p)ans.push_back(i);
         }
         return ans;
    }
    
    string normalize(string s){
        map<char,int> m;
        for(auto i: s){
            if(m.find(i)==m.end())m[i]=m.size();
        }
        for(auto &i: s)i='a'+m[i];
        return s;
    }
};