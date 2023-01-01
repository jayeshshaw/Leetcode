class Solution {
    
private:
    vector<vector<int>> ans;
    void f(int ind,vector<int> &v, int target,int k, vector<int> combi){
        if(ind==v.size()){
            if(target==0 && k==0){ans.push_back(combi);return;}
            return;
        }
        
        f(ind+1,v,target, k,combi);
        
        if(target>=v[ind]){
            combi.push_back(v[ind]);
            f(ind+1,v,target-v[ind],k-1,combi);
        }
        
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v={1,2,3,4,5,6,7,8,9};
        f(0,v,n,k,{});
        return ans;
    }
};