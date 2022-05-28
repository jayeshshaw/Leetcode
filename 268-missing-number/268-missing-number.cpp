class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sm=(n*(n+1))/2;
        sm-=accumulate(nums.begin(),nums.end(),0);
        return sm;
    }
};