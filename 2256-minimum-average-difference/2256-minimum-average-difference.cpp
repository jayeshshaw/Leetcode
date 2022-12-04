class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int sm=0;
        int n=nums.size();
        for(auto i: nums)sm+=i;
        long long int s=0;
        int mn=1e9,ind=-1;
        for(int i=0;i<n;i++){
            if(i==n-1){
                if(sm/n<mn){
                    ind=i;
                }
                return ind;
            }
            s+=nums[i];
            int avg=(s/(i+1)) -((sm-s)/(n-i-1));
            avg=abs(avg);
            
            if(avg<mn){
                mn=avg;ind=i;
            }
        }
        return ind;
    }
};