//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        if(s.size()==0)return "-1";
        string ans="";
        int n=s.size();
        int i;
        for(i=0;i<n-1;i++){
            if(s[i]==s[i+1]){i++;continue;}
            ans+=s[i];
        }
        if(i==n-1)ans+=s[i];
        if(ans==s)return s;
        else return removePair(ans);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends