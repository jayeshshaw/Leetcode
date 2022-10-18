class Solution {
public:
    void make(string &ans,int p, char val){
        if(p==1)ans+="1";
        else if(p==2){ans+="2";}
        else if(p==3){ans+="3";}
        else if(p==4){ans+="4";}
        else if(p==5){ans+="5";}
        else if(p==6){ans+="6";}
        else if(p==7){ans+="7";}
        else if(p==8){ans+="8";}
        else if(p==9){ans+="9";}
        ans+=val;
    }
    
    string countAndSay(int n) {
        if(n==1)return "1";
        string s=countAndSay(n-1);
        string ans="";
        for(int i=0;i<s.size();){
            int p=0;
            char val=s[i];
            while(i<s.size() && s[i]==val)p++,i++;
            make(ans,p,val);
        }
        return ans;
    }
};