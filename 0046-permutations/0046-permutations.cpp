class Solution {
public:
    
    int fact(int n){if(n==1)return 1; return n*fact(n-1);}
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v=nums;
        vector<vector<int>> ans;
        ans.push_back(v);
        int n=nums.size();
        
        int poss=fact(n);poss--;
        
        while(poss--){
            next_permutation(begin(v),end(v));
            ans.push_back(v);
        }
        return ans;
    }
};