class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<string ,char> m;
        map< char,string> mm;
        vector<string> helper;
        for(int i=0;i<s.size();i++){
            string p;
            while(i<s.size()&&s[i]!=' ' ){
                p.push_back(s[i++]);
            }
            helper.push_back(p);
        }
        if(pattern.size()!=helper.size())return false;
        for(int i=0;i<pattern.size();i++){
           if(m.find(helper[i])==m.end()){
               m[helper[i]]=pattern[i];
           }
            else{
                if(m[helper[i]]!=pattern[i])return false;
            }
            if(mm.find(pattern[i])==mm.end()){
               mm[pattern[i]]=helper[i];
           }
            else{
                if(mm[pattern[i]]!=helper[i])return false;
            }
        }
        return true;
    }
};