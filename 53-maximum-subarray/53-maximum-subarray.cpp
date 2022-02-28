class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int max_sum=a[0],sum=0,n=a.size();
        for(int i=0;i<n;i++){
            sum+=a[i];
            max_sum=max(sum,max_sum);
            if(sum<0)sum=0;
        }                
        return max_sum;
    }
};