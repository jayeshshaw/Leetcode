//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int a, int b, int c, int d){
        int ans=0;
        int mn=min(c,d),mx=max(c,d);
        c=mn,d=mx;
        while(a>d || b>d){
            if(a>d)ans++,a=a/2;
            if(b>d)ans++,b=b/2;
        }
        mn=min(a,b),mx=max(a,b);
        a=mn,b=mx;
        while(a>c){
            a=a/2;
            ans++;
        }
        return ans;
        
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends