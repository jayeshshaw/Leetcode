class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        if(n==0)return true;
        if(f.size()==1 && f[0]==0 && n<=1)return true;
        else if(f.size()==1)return false;
        
        if(f[0]==0 && f[1]==0){n--;f[0]=1;}
        if(f[f.size()-1]==0 && f[f.size()-2]==0){n--;f[f.size()-1]=1;}
        if(n<1)return true;
        
        
        for(int i=1;i<f.size()-1;i++){
            if(f[i]==0 && f[i-1]==0 && f[i+1]==0){n--;f[i]=1;}
            if(n<1)return true;
        }
        
        return n<1;
    }
};