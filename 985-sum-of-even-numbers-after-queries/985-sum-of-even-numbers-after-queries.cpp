class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int ans=0;
        for(auto i: nums){
            if(i%2==0)ans+=i;
        }
        vector<int> vans;
        for(auto i: queries){
            int ind=i[1];
            int val=i[0];
            
            int prev=nums[ind];
            nums[ind]+=val;
            
            if(prev%2==0){
                if(nums[ind]%2==0)ans+=nums[ind]-prev;
                else ans-=prev;
                vans.push_back(ans);
            }
            else{
                if(nums[ind]%2==0)ans+=nums[ind];
                vans.push_back(ans);
            }
        }
        return vans;
    }
};