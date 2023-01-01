class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();        
        
        vector<int> prefix=nums;
        for(int i=1;i<n;i++)prefix[i]+=prefix[i-1];
        
        int ind=lower_bound(begin(prefix),end(prefix),target)-begin(prefix);
        if(ind==n)return 0;
        
        int ans=ind+1;
        
        for(int i=0;i<n;i++){
            int ele=nums[i];
            ind=lower_bound(begin(prefix),end(prefix),target+prefix[i])-begin(prefix);
            if(ind==n)continue;
            ans=min(ans,ind-i);
        }
        return ans;
        
    }
};