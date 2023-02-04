class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size())return false;
        vector<int> h(26,0);
        for(auto i: s1)
            h[i-'a']++;
        
        for(int i=0;i<=s2.size()-s1.size();i++){
            vector<int> hh(26,0);
            for(int j=i;j<i+s1.size();j++){
                 hh[s2[j]-'a']++;
            }
            if(h==hh)return true;
        }
        return false;
    }
};