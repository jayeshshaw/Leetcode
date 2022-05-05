class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        int m=pow(2,maximumBit);
        vector<int> pf(n,0);
        pf[0]=nums[0];
        for(int i=1;i<n;i++){
            pf[i]=pf[i-1]^nums[i];
        }
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
           ans.push_back(pf[i]^m-1);
        }
        // cout<<n*m;
        return ans;
    }
};