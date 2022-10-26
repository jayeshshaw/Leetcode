class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l=0,r=0;
        for(int i: nums)l=max(l,i),r+=i;
        
        int ans=0;
        
        while(l<=r){
            int mid=(l+r)/2;
            
            int running_sum=0;
            int subarrays=0;
            
            for(int i: nums){
                running_sum+=i;
                if(running_sum>mid){
                    running_sum=i;
                    subarrays++;
                }
                if(subarrays>k)break;
            }
            
            if(subarrays<k)r=mid-1;
            else {ans=mid;l=mid+1;}
        }
        return l;
    }
};