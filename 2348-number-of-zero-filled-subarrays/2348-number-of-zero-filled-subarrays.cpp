class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){continue;}
            long long p=0;
            while(i<nums.size() && nums[i]==0)i++,p++;
            ans+=(p*(p+1))/2;
        }
        return ans;
    }
};