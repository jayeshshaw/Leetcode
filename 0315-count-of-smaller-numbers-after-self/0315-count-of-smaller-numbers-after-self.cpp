class Solution {
public:
    vector<int> fin;
    
     void inPlaceMerge(vector<pair<int,int>> &nums, int low, int mid, int high) {
        if (low >= high) return ;
        //  for(int i=low;i<=high;i++){
        //     cout<<nums[i]<<" ";
        //     if(i==mid)cout<<"| ";
        // }       
        // cout<<" ->";
        int i=low,j=mid+1;
        while(i<=mid){
            while(j<=high && nums[i].first>(nums[j].first))j++;
            fin[nums[i].second]+=j-(mid+1);i++;
        }
         // for(auto i: fin)cout<<i<<" ";
         // cout<<endl;
         
        int l = low, r = mid + 1, k = 0, size = high - low + 1;
        vector<pair<int,int>> sorted(size);
        while (l <= mid and r <= high)
            sorted[k++] = nums[l].first <= nums[r].first ? nums[l++] : nums[r++];
        while (l <= mid) 
            sorted[k++] = nums[l++];
        while (r <= high) 
            sorted[k++] = nums[r++];
        for (k = 0; k < size; k++)
            nums[k + low] = sorted[k];
        
    }

    void mergeSort(vector<pair<int,int>> &nums, int low, int high) {
        if (low >= high) return ;
        int mid = (high - low) / 2 + low;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        inPlaceMerge(nums, low, mid, high);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> v;
        fin.resize(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        mergeSort(v,0,v.size()-1);
        return fin;
    }
};