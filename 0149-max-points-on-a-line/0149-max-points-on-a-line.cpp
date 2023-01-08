class Solution {
public:
    int maxPoints(vector<vector<int>>& v) {
        int n=v.size();
        int ans=min(2,n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int abhi=2;
                float ix=v[i][0],iy=v[i][1];
                float jx=v[j][0],jy=v[j][1];
                
                for(int  k=j+1;k<n;k++){
                    
                    float kx=v[k][0],ky=v[k][1];
                    
                    long long s1=(ky-iy)*(kx-jx);
                    long long s2=(ky-jy)*(kx-ix);
                    
                    if(s1==s2 )abhi++;
                    
                }
                ans=max(abhi,ans);
            }
        }
        return ans;
    }
};