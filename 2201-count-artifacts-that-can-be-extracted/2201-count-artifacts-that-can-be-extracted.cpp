class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& a, vector<vector<int>>& dig) {
        vector<vector<int>> vis(n,vector<int> (n,0));
        for(int i=0;i<dig.size();i++){
            vis[dig[i][0]][dig[i][1]]=1;
        }
        
        int ans=0;
        for(int i=0;i<a.size();i++){
            bool done=true;
            for(int p=a[i][0];p<=a[i][2];p++){
                for(int q=a[i][1];q<=a[i][3];q++){
                    if(vis[p][q]==0){done=false;}
                }
            }
            if(done)ans++;
        }
        return ans;
    }
};