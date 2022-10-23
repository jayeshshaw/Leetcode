class Solution {
public:
    int findMin(vector<int>& nums){
        int n = nums.size(), start = 0, mid = 0, end = nums.size() - 1;
        
        if(nums[start]<=nums[end])return nums[0];
        
        
        while(start <= end){
            mid = start + (end - start) / 2;
            int next = (mid + 1) % n;
            int prev = (mid + n - 1) % n;
            if(nums[mid] < nums[prev] && nums[mid] < nums[next]) return nums[mid];
            else if(nums[end] < nums[mid]) start = mid + 1;
            else end = mid -1 ;
        }
        return -1;
    }
};