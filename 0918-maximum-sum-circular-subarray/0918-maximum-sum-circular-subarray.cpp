class Solution {

private:
    int minSumSubarray(vector<int> &v){
        int ans=INT_MAX,sm=0;
        for(auto i: v){
            sm+=i;
            ans=min(ans,sm);
            sm=min(0,sm);
        }
        return ans;
    }
    
    int maxSumSubarray(vector<int> &v){
        int sm=0,ans=INT_MIN;
        for(auto i: v){
            sm+=i;
            ans=max(ans,sm);
            sm=max(0,sm);
        }
        return ans;
    }

public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mn=minSumSubarray(nums);
        int sum=0;
        for(auto i: nums)sum+=i;
        
        int mx=maxSumSubarray(nums);
        if(mx<=0)return mx;
        int ans=max(sum-mn,mx);
        return ans;
    }
};