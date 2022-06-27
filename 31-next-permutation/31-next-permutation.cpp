class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i;
        for(i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1])break;
        }
        if(i<0)reverse(nums.begin(),nums.end());
        else{
            int ind;
            for( ind=n-1;ind>i;ind--){
                if(nums[ind]>nums[i])break;
            }
            // cout<<ind<<" "<<i; 
            swap(nums[i],nums[ind]);
            reverse(nums.begin()+i+1,nums.end());
        }
        
    }
};