class Solution {
public:
    bool canConstruct(string r, string m) {
        if(m.size()<r.size())return false;
        int a[26]={0};
        for(auto i: m)a[i-'a']++;
        
        for(int i=0;i<r.size();i++){
            if(a[r[i]-'a']<=0)return false;
            else a[r[i]-'a']--;
        }
        return true;
    }
};