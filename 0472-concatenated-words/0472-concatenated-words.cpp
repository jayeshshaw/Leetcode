class Solution {

private:
    unordered_set<string> st;
    bool ok(string s, int ind, int cnt){
        if(ind==s.size())return cnt>=2;
        string p="";
        for(int i=ind;i<s.size();i++){
            p+=s[i];
            if(st.count(p)>0 && ok(s,i+1,cnt+1))return 1;
        }
        return 0;
    }
    
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& v) {
        vector<string> ans;
        for(auto i: v)st.insert(i);
        for(auto w: v){
            if(ok(w,0,0))ans.push_back(w);
        }
        return ans;
    }
};