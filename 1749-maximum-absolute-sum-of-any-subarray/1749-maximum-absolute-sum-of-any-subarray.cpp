class Solution {
public:
    int maxAbsoluteSum(vector<int>& a) {
        int max_sum=a[0],sum=0,n=a.size();
        for(int i=0;i<n;i++){
            sum+=a[i];
            max_sum=max(sum,max_sum);
            if(sum<0)sum=0;
        }   
        int min_sum;sum=0;
        for(int i=0;i<n;i++)a[i]*=-1;
        for(int i=0;i<n;i++){
            sum+=a[i];
            max_sum=max(sum,max_sum);
            if(sum<0)sum=0;
        }
        return max(max_sum,min_sum);
    }
};