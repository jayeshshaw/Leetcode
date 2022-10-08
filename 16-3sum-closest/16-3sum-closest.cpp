class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int dif=INT_MAX,n=nums.size();
        int ans=1e9;
        sort(begin(nums),end(nums));
        for(int i=0;i<n;i++){
            if(ans==target)break;
            int required=target-nums[i];
            int left=i+1,right=n-1;
            while(left<right){
                if(dif>abs((nums[left]+nums[right])-required)){
                    dif=abs((nums[left]+nums[right])-required);ans=nums[left]+nums[right]+nums[i];
                }
                if(nums[left]+nums[right]>required)right--;
                else if(nums[left]+nums[right]<required)left++;
                else break;
            }
        }
        return ans;
    }
};