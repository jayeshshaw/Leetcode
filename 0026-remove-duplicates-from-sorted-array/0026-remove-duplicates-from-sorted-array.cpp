class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        while(j<n){
            int k=nums[j];
            nums[i++]=k;
            while(j<n && nums[j]==k)j++;
        }
        return i;
    }
};