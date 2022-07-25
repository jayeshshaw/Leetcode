class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v(2,-1);
        int n=nums.size();
        if(nums.size()==1 && nums[0]==target)return {0,0};
        int left=0,right=n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            
            if(nums[mid]==target){
                right=mid-1;
                v[0]=mid;
            }
            else if(nums[mid]>target) right=mid-1;
            else left=mid+1;
        }
        
        left=0,right=n-1;
        
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                left=mid+1;
                v[1]=mid;
            }
            else if(nums[mid]>target) right=mid-1;
            else left=mid+1;
        }
        return v;
    }
};