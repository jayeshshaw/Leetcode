class Solution {
public:
    vector<vector<int>> v;
    vector<int> t;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
             
        knapsack(0,candidates,target);
        return v;
    }
    void knapsack(int i,vector<int> c,int tar){
        if(i==c.size()){
            if(tar==0){v.push_back(t);}
            return ;
        }
        
        if(c[i]<=tar){
            t.push_back(c[i]);
            knapsack(i,c,tar-c[i]);
            t.pop_back();            
        }
        knapsack(i+1,c,tar);
        
        
    }
    
};