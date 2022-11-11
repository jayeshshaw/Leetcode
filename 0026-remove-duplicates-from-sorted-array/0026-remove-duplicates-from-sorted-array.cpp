class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0;
        int n=nums.size();
        while(j<n){
            int k=nums[j];
            nums[i++]=k;
            while(j<n && nums[j]==k)j++;
        }
        return i;
    }
};