class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size())return {};
        vector<int> ans;
        vector<int> hp(26,0);
        for(auto i: p)hp[i-'a']++;
        for(int i=0;i<=s.size()-p.size();i++){
            vector<int> hs(26,0);
            for(int j=i;j<p.size()+i;j++)hs[s[j]-'a']++;
            
            if(hs==hp)ans.push_back(i);
        }
        return ans;
    }
};