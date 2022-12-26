class Solution {
public:
    bool canJump(vector<int>& v) {
        int reach=v[0];
        int n=v.size();
        for(int i=1;i<=min(reach,n-1);i++){
            reach=max(reach,i+v[i]);
        }
        return reach>=n-1;
    }
};