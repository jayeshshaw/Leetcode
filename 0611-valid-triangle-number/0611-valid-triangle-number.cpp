class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        int triplets=0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a=nums[i];
                int b=nums[j];
                int ind=lower_bound(begin(nums)+j+1,end(nums),a+b)-(begin(nums));
                triplets+=(ind-1)-j;
            }
        }
        return triplets;
    }
};