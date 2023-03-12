class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans=0,n=nums.size();
        unordered_map<int,int> mp;
        int xr=0;
        mp[xr]=1;
        for(int i=0;i<n;i++){
            xr^=nums[i];
            ans+=mp[xr];
            mp[xr]++;
        }
        return ans;
    }
};