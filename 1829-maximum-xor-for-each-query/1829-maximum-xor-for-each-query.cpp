class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int k=pow(2,maximumBit)-1;
        int n=nums.size();
        vector<int> pre(n,0),ans(n,0);
        int ii=0;
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=nums[i]^pre[i-1];
        }
        for(int i=n-1;i>=0;i--){
            ans[ii++]=pre[i]^k;
        }
        return ans;
    }
};