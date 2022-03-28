class Solution {
public:
    bool search(vector<int>& nums, int t) {
        int l=0,r=nums.size()-1,m;
        while(l<=r){
            m=(l+r)/2;
            if(nums[m]==t)return 1;
            if(nums[m]>nums[r]){
                if(t<nums[m] && t>nums[r])r=m-1;
                else l=m+1;
            }
            else if(nums[m]<nums[l]){
                if(nums[m]<t && nums[l]>t)l=m+1;
                else r=m-1;
            }
            else {
                for(int i=l;i<=r;i++){
                    if(nums[i]==t)return true;
                }
                return 0;
            }
        }
        return 0;
    }
};