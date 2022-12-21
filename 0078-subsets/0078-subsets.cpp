class Solution {
public:
    set<vector<int>> st;
    void f(int i, vector<int> v,vector<int> abhi){
        if(i==v.size()){st.insert(abhi);return;}
        f(i+1,v,abhi);
        abhi.push_back(v[i]);
        f(i+1,v,abhi);
        
    }
    
    vector<vector<int>> subsets(vector<int>& v) {
        f(0,v,{});
        vector<vector<int>> ans;
        for(auto i: st)ans.push_back(i);
        return ans;
    }
};