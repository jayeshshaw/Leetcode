class Solution {
public:
    int mirrorReflection(int p, int q) {
        if(p%q==0){
            if((p/q)%2==0)return 2;
            else return 1;
        } 
        int ext=q,ref=p;
        while(ext%2==0 && ref%2==0){ext/=2;ref/=2;}
        if(ext%2==0 && ref%2!=0)return 0;
        if(ext%2!=0 && ref%2==0)return 2;
        return 1;
    }
};