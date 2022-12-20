class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();

        int l=0,r=1;
        while(r<n){
            if(nums[l]==0 && nums[r]!=0){swap(nums[l++],nums[r++]);}
            else if((nums[l] && nums[r]) || (nums[l] && !nums[r]))l++,r++;
            else if(!nums[l] && !nums[r])r++;
        }
    }
};