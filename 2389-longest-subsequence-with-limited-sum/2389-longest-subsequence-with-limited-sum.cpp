class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        sort(begin(nums),end(nums));
        int n=nums.size();
        for(int i=1;i<n;i++)nums[i]+=nums[i-1];
        
        for(auto i: queries){
            int val=i;
            int ind=upper_bound(begin(nums),end(nums),val)-begin(nums);
            ans.push_back(ind);
        }
        return ans;        
    }
};