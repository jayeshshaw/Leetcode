class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        for(int i=1;i<nums.size();i++){
            ans+=max(nums[i-1]+1,nums[i])-nums[i];
            nums[i]=max(nums[i-1]+1,nums[i]);
        }
        return ans;
    }
};