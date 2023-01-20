class Solution {
private:
    vector<vector<int>> ans;
    void f(int i, vector<int> &v, vector<int> subs){
        if(i==v.size()){if(subs.size()>1) ans.push_back(subs);return;}
        
        if(subs.size()==0 || subs.back()<=v[i])subs.push_back(v[i]);
        f(i+1,v,subs);
        subs.pop_back();
        f(i+1,v,subs);
    }
    
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        ans.resize(0);
        f(0,nums,{});
        sort(ans.begin(),end(ans));
        vector<vector<int>> v;
        if(ans.size()>0)v.push_back(ans[0]);
        for(int i=1;i<ans.size();i++){
            if(ans[i]==ans[i-1])continue;
            v.push_back(ans[i]);
        }
        return v;
    }
};