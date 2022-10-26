class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n,nums[0]);
        for(int i=1;i<n;i++)prefix[i]=prefix[i-1]+nums[i];
        unordered_map<int,int> mp;
        mp[0]=-1;
        bool ans=0;
        for(int i=0;i<n;i++){
            int rem=prefix[i]%k;
            
            // cout<<mp[rem]<<" ";   // agr ye uncommented rahega to mp[rem]=0 ho jayga;
            
            
            mp.insert({rem,i});  // agr nhi h to insert krega wrna kch nhi krega
            
            if(i-mp[rem]>1)ans=1;
            // cout<<i<<" "<<mp[rem]<<" "<<ans<<endl;
        }
        
        return ans;
        
        
    }
};