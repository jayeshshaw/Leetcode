class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=0;
        int odds=0;
        int nice_subarrays=0;
        int size=nums.size();
        
        for(int i=0;i<size;i++){
            if(nums[i]%2)odds++;
            if(mp[odds]==0 && odds>0)mp[odds]=i+1;
            if(odds-k>=0)
            nice_subarrays+= mp[odds-k+1] - mp[odds-k];
            // cout<<i<<" "<<odds-k<<"-->  "<<mp[odds-k+1]<<"-"<<mp[odds-k]<<endl;
        }
        
        return nice_subarrays;
    }
};