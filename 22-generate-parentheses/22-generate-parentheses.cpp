class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        makeans(ans,n,0,"");
        return ans;
    }
    
    void makeans(vector<string> &ans, int n,int m,string s){
        if(n==0 && m==0){
            ans.push_back(s);return;
        }
        if(m>0)makeans(ans,n,m-1,s+')');
        if(n>0)makeans(ans,n-1,m+1,s+'(');
        
    }
};