class Solution {
public:
    double champagneTower(int p, int r, int g) {
        vector<vector<double>> v(102,vector<double> (102,0));
        v[0][0]=p;
        for(int i=0;i<r;i++){
            for(int j=0;j<=i;j++){
                double flow=(v[i][j]-1)/2.0;
                if(flow>0){
                    v[i+1][j]+=flow;
                    v[i+1][j+1]+=flow;
                }
            }
        }
        return min(1.0,v[r][g]);
       
    }
};