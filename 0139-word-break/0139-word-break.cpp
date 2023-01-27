class Solution {
private:
    unordered_map<string,int> mp;
    map<vector<int>,int> m;
    bool ok(string s, int ind, int cnt){
        if(ind==s.size())return cnt>=2;
        
        if(m.find({ind,cnt})!=m.end())return m[{ind,cnt}];
        
        string p="";
        for(int i=ind;i<s.size();i++){
            p+=s[i];
            if(mp[p]!=0 && ok(s,i+1,cnt+1))return m[{ind,cnt}]=1;
        }
        return m[{ind,cnt}]=0;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto i: wordDict)mp[i]=1;
        return ok(s,0,0) || mp[s]==1;
    }
};