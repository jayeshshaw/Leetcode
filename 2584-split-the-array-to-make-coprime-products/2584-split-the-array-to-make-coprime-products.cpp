class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> pos;
        vector<vector<int>> pf(n);
        for(int i=0;i<n;i++){
            int x=nums[i];
            for(int j=2;j*j<=x;j++){
                if(x%j==0){
                    pos[j]=i;
                    pf[i].push_back(j);
                    while(x%j==0)x/=j;
                }
            }
            if(x>1){
                pos[x]=i;
                pf[i].push_back(x);
            }
        }
        int mx=-1;
        for(int i=0;i<n-1;i++){
            for(int j: pf[i]){
                mx=max(mx,pos[j]);
            }
            if(mx==i)return i;
        }
        return -1;
    }
};