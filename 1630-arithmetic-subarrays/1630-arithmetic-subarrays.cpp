class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size(),true);
        for(int i=0;i<l.size();i++){
            vector<int> p;
            for(int k=l[i];k<=r[i];k++)p.push_back(nums[k]);
            sort(p.begin(),p.end());
            for(int j=2;j<p.size();j++){
                if(abs(p[j]-p[j-1])!=abs(p[j-1]-p[j-2])){ans[i]=false;break;}
            }
        }
        return ans;
    }
};