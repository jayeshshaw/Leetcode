// #define int long long
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        int minimum_difference=INT_MAX;
        int index=0;
        long long int total=0;
        for(int i: nums)total+=i;
        
        long long int left=0,right;
        for(int i=0;i<n-1;i++){
            left+=nums[i];
            right=total-left;
            int abs_difference=abs((left/(i+1))-(right/(n-i-1)));
            if(abs_difference<minimum_difference){
                minimum_difference=abs_difference;
                index=i;
            }
        }
        int abs_difference=abs(total/n);
        if(abs_difference<minimum_difference){
            minimum_difference=abs_difference;
            index=n-1;
        }
        return index;
    }
};