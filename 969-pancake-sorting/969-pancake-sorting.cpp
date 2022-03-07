class Solution {
public:
    int max_ind(vector<int> a,int n){
        int mx=INT_MIN,mxi=0;
        for(int i=0;i<n;i++){
            if(a[i]>mx){
                mx=a[i];
                mxi=i;
            }
        }
        return mxi;
    }
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        int n=arr.size();
        for(int i = 0;i < arr.size();i++){
           auto maxPosition = max_element(arr.begin(), arr.end() - i);
           ans.push_back(maxPosition  - arr.begin() + 1);  
           ans.push_back(arr.size() - i);
           reverse(arr.begin(),maxPosition+1);
           reverse(arr.begin(),arr.end() - i);
        }
        return ans;
    }
};