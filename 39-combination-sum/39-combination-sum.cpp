class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
    vector<vector<int>> r;
        vector<int> d;
        dothething(0,target,candidates,r,d);
        return r;
    }
    
    void dothething(int i, int t,vector<int>& arr,vector<vector<int>>& r, vector<int>& d ){
        if(i==arr.size()){
            if(t==0)
                r.push_back(d);
            return;}
        
        if(arr[i]<=t){
            d.push_back(arr[i]);
             dothething(i,t-arr[i],arr,r,d);
            d.pop_back();
        }
        
        dothething(i+1,t,arr,r,d);
        return;
    
    }
};