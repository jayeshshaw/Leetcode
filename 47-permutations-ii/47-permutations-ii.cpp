class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         set<vector<int>> ans;
        makeans(nums,0,ans);
        vector<vector<int>> res;
        for(auto i: ans){
            res.push_back(i);
        }
        return res;
    }
    
    void makeans(vector<int> nums, int l, set<vector<int>> & ans){
        if(l==nums.size()){
            ans.insert(nums);
            return;
        }
        
        for(int i=l;i<nums.size();i++){
            swap(nums[i],nums[l]);
                makeans(nums,l+1,ans);
            swap(nums[i],nums[l]);
        }
    }
};