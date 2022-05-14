class Solution {
public:
    
    int maximumWhiteTiles(vector<vector<int>>& v, int l) {
        int n=v.size();
        sort(v.begin(),v.end());
        int j=0,i=0,cover=0,res=0;
        for(i=0;i<n;){
            if(i==j || v[j][0]+l>v[i][1]){
                cover+=v[i][1]-v[i][0]+1;
                res=max(res,cover);
                i++;
            }
            else{
                res=max(res,cover+max(0,v[j][0]+l-v[i][0]));
                cover-=v[j][1]-v[j][0]+1;
                j++;
            }
        }
        return min(res,l);
    }
};