class Solution {
public:
    int search(vector<int>& nums, int t) {
        int l=0,r=nums.size()-1,m;
        while(l<=r){
            m=(l+r)/2;
            if(nums[m]==t)return m;
            else if(nums[m]>nums[r]){
                if(t<nums[m] && t>=nums[l])r=m-1;
                else l=m+1;
            }
            else if(nums[m]<nums[l]){
                if(t>nums[m] && t<=nums[r])l=m+1;
                else r=m-1;
            }
            else{
                if(t>nums[m])l=m+1;
                else r=m-1;
            }
        }
        return -1;
    }
};