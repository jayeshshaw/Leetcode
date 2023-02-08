class Solution {
public:
    int kthSmallest(vector<vector<int>>& v, int k) {
        int n=v.size();
        int left=v[0][0];
        int right=v[n-1][n-1];
        int mid;
        while(left<right){
            mid=left+(right-left)/2;
            int count=0;
            for(int i=0;i<n;i++){
                int ele=upper_bound(v[i].begin(),end(v[i]),mid)-begin(v[i]);
                count+=ele;
            }
            if(count<k)left=mid+1;
            else right=mid;
        }
        return left;
    }
};