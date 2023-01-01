class Solution {
    
    
private:
    vector<vector<int>> ans;
    void f(int ind, vector<int> &v, vector<int> combi,int target){
        // if(ind==v.size()){
            if(target==0){ans.push_back(combi);return;}
            // return;
        // }
        
        
        for(int j=ind;j<v.size();j++){
            if(j>ind && v[j]==v[j-1])continue;
            if(target<v[j])break;
            combi.push_back(v[j]);
            f(j+1,v,combi,target-v[j]);
            combi.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates),end(candidates));
        f(0,candidates,{},target);
        return ans;
    }
};