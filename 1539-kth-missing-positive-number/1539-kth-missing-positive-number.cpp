class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int last=0,n=arr.size();
        for(int i=0;i<n;i++){
            int gap=arr[i]-last-1;
            if(k>gap)k-=arr[i]-last-1;
            else return last+k;
            last=arr[i];
        }
        return last+k;
    }
};