class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sm=(n*(n+1))/2;
        for(auto i: nums)sm-=i;
        return sm;
    }
};