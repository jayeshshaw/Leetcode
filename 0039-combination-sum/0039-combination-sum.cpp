class Solution {
public:
    vector<vector<int>> ans;
    
    void f(int ind, vector<int> &v, vector<int> combi,int target){
        if(ind==v.size()){
            if(target==0)ans.push_back(combi);
            return;
        }
        
        f(ind+1,v,combi,target);
        if(target>=v[ind]){
            combi.push_back(v[ind]);
            target-=v[ind];
            f(ind,v,combi,target);
        }        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        f(0,candidates,{},target);
        return ans;
    }
};