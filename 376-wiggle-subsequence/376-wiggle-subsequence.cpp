class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n<2)return n;
        
        int ans=1,sign=0;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1] && sign!=1){sign =1;ans++;}
            else if(nums[i-1]>nums[i] && sign !=-1){sign=-1;ans++;}
        }
        return ans;
    }
};