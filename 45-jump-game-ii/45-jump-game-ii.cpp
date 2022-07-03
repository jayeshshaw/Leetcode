class Solution {
public:
    int jump(vector<int>& nums) {
        
        
        // NORMAL SOLUTION  TC- N  SC- 1
        int n=nums.size(),end=0,max_reach=0,ans=0;
        for(int i=0;i<n-1;i++){
            max_reach=max(max_reach,i+nums[i]);
            
            if(i==end){
                ans++;
                end=max_reach;
            }
        }
        return ans;
        
        
        
        
        
        // DP SOLUTION    TC-N^2   SC- N 
        
//         int n=nums.size();
//             if(n==1)return 0;
//         vector<int> dp(n+1,0);
        
//         for(int i=n-2;i>=0;i--){
//             int j=nums[i];
//             int k=i+1;
//             int mn=dp[i+1];
//             for(int k=i+1;k<n && k<=i+nums[i];k++)
//                 mn=min(mn,dp[k]);
            
//             dp[i]=1+mn;
//         }
        
//         return dp[0];
    }
};