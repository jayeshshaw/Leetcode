class Solution {
public:
    int jump(vector<int>& v) {
        int n=v.size();
        int kahatk=0;
        int ans=0;
        int max_reach=0;
        for(int i=0;i<n-1;i++){
            max_reach=max(max_reach,i+v[i]);
            if(i==kahatk){
                ans++;kahatk=max_reach;
            }
        }
        return ans;
    }
};