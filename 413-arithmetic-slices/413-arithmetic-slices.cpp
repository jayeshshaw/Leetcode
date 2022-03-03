class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0;
        if(nums.size()<3)return 0;
        int l=0;
        for(int i=2;i<nums.size();i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){l++;}
            else {ans+=l*(l+1)/2;l=0;}
        }
        if(l!=0)ans+=l*(l+1)/2;
        return ans;
    }
};