//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int countPaths(int n){
        int mod=1e9+7;
    int waysD=1,waysABC=0;
    for(int i=1;i<=n;i++){
        int iwaysD= (waysABC*3ll)%mod;
        int iwaysABC= ((waysABC*2)%mod+ (waysD)%mod)%mod;
 
        waysD=iwaysD;
        waysABC=iwaysABC;
    }
 
    return waysD;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends