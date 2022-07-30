class Solution {
public:
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        
        vector<int> cnt(26,0),tmp(26,0);
        for(string b: words2){
            tmp=freq(b);
            for(int i=0;i<26;i++){
                cnt[i]=max(cnt[i],tmp[i]);
            }
        }
        
        for(string a: words1){
            tmp=freq(a);
            int i;
            for( i=0;i<26;i++){
                if(tmp[i]<cnt[i])break;
            }
            if(i==26)ans.push_back(a);            
        }
        return ans;
        
    }
    
    vector<int> freq(string &s){
        vector<int> v(26,0);
        for(auto i: s)v[i-'a']++;
        return v;
    }
};