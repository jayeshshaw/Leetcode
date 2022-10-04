class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int ans=-1;
        int n=nums.size();
        
        if(n==1 && k&1)return ans;
        
        for(int i=0;i<min(k-1,n);i++)ans=max(ans,nums[i]);
        if(k<n)ans=max(ans,nums[k]);
        return ans;
    }
};