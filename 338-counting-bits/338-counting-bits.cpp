class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<=n;i++){
            int t=0;
            int p=i;
            while(p!=0){
                if(p&1!=0)t++;
                p=p>>1;
            }
            ans.push_back(t);
        }
        return ans;
        
    }
};