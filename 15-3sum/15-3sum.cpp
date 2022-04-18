class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int a,b=nums.size()-1;
        for(int i=0;i<n;){
            a=i+1;b=nums.size()-1;
            int k=(-1)*nums[i];
            while(a<b){
                // cout<<a<<" "<<b<<" "<<k<<endl;
                if(nums[a]+nums[b]==k){
                    ans.push_back({nums[i],nums[a],nums[b]});
                    int x=nums[a],y=nums[b];
                    while(a<b && nums[a]==x && nums[b]==y){a++;b--;}
                }
                else if(nums[a]+nums[b]<k)a++;
                else b--;
            }
            int p=nums[i];
            while(i<n && nums[i]==p)i++;
            
        }
        return ans;
    }
    
};