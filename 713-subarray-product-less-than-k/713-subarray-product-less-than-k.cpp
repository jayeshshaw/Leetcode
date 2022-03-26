class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0,n=nums.size();
        if(k<=1)return 0;
        int p=1,l=0;
        for(int i=0;i<n;i++){
            p*=nums[i];
            while(p>=k){
                p/=nums[l++];
            }
            ans+=i-l+1;
        }
        return ans;
    }
};