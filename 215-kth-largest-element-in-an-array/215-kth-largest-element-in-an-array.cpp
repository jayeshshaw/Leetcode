class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        multiset<int> s(nums.begin(),nums.end());
        auto it=s.begin();
        advance(it,n-k);
        return *it;
    }
};