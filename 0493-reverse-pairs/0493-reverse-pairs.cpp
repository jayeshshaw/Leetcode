class Solution {
public:
    
    int inPlaceMerge(vector<int> &nums, int low, int mid, int high) {
        if (low >= high) return 0;
        
        // for(int i=low;i<=high;i++){
        //     cout<<nums[i]<<" ";
        //     if(i==mid)cout<<"| ";
        // }       
        // cout<<" ->";
        
        int ans=0;
        int i=low,j=mid+1;
        while(i<=mid){
            while(j<=high && nums[i]>(2LL*nums[j]))j++;
            ans+=j-(mid+1);i++;
        }
        // cout<<ans<<endl;
        
        
//         int l = low, r = mid + 1, size = high - low + 1;
//         while (l <= mid and r <= high) {
//             if (nums[l] <= nums[r]) l++;
//             else {
//                 int val = nums[r];
//                 for (int k = r++; k > l; k--)
//                     nums[k] = nums[k - 1];
//                 nums[l++] = val;
//                 mid++;
//             }
//         }
        
        int l = low, r = mid + 1, k = 0, size = high - low + 1;
        vector<int> sorted(size, 0);
        while (l <= mid and r <= high)
            sorted[k++] = nums[l] <= nums[r] ? nums[l++] : nums[r++];
        while (l <= mid) 
            sorted[k++] = nums[l++];
        while (r <= high) 
            sorted[k++] = nums[r++];
        for (k = 0; k < size; k++)
            nums[k + low] = sorted[k];
        
        return ans;
    }

    int mergeSort(vector<int> &nums, int low, int high) {
        if (low >= high) return 0;
        int mid = (high - low) / 2 + low;
        int ans=mergeSort(nums, low, mid);
        ans+=mergeSort(nums, mid + 1, high);
        ans+=inPlaceMerge(nums, low, mid, high);
        return ans;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};