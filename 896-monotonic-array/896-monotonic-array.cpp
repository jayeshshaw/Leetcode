class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int inc=0,dec=0;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]>=nums[i-1])inc++;
            if(i<nums.size()-1 && nums[i]>=nums[i+1])dec++;
        }
        cout<<inc<<" "<<dec<<" ";
        return inc==nums.size()-1 || dec==nums.size()-1;
    }
};