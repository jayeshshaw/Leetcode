class Solution {
public:
    int ans=0;
    int f(int i,int j, vector<int>& a, vector<int>& b,vector<vector<int>> &dp){
        if(i<0 || j<0)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int abhi=0;
        if(a[i]==b[j]){
            abhi= 1+ f(i-1,j-1,a,b,dp);
        }
        ans=max(ans,abhi);
        f(i-1,j,a,b,dp);
        f(i,j-1,a,b,dp);
        return dp[i][j]=abhi;
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // int ans=0;
        // map<vector<int>,int> mp;
        // int n=nums1.size();
        // for(int i=0;i<n;i++){
        //     vector<int> v;
        //     v.push_back(nums1[i]);
        //     if(mp[v]==0)
        //     mp[v]++;
        //     for(int j=i+1;j<n;j++){
        //         v.push_back(nums1[j]);
        //         if(mp[v]==0)
        //         mp[v]++;
        //     }
        // }
        // n=nums2.size();
        // for(int i=0;i<n;i++){
        //     vector<int> v;
        //     v.push_back(nums2[i]);
        //     if(mp[v]>0)
        //         ans=max(ans,(int)(v.size()));
        //     for(int j=i+1;j<n;j++){
        //         v.push_back(nums2[j]);
        //         if(mp[v]>0)
        //             ans=max(ans,(int)(v.size()));
        //     }
        // }
        // return ans;
        ans=0;
        vector<vector<int>> dp(nums1.size(),vector<int> (nums2.size(),-1));
        f(nums1.size()-1,nums2.size()-1,nums1,nums2,dp);
        return ans;
    }
};