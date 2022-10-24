class Solution {
public:
    int ans=0;
    
    bool unique(string s){
        vector<int> v(26,0);
        for(auto i: s){
            if(v[i-'a']>0)return 0;
            v[i-'a']++;
        }
        return 1;
    }
    
    void f(int i, vector<string> &v, string s){
        if(i==v.size()){
            if(unique(s))ans=max(ans,int(s.size()));
            return;
        }
        f(i+1,v,s);
        s+=v[i];
        f(i+1,v,s);
    }
    int maxLength(vector<string>& arr) {
        f(0,arr,"");
        return ans;
    }
};