// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
int n;
int calc(int a[]){
    int mn=1e5,mx=0;
    for(int i=0;i<n;i++){
        int I=a[i];
        mx=max(mx,I);
        mn=min(mn,I);
        // cout<<I<<" ";
    }
    // cout<<endl;
    // cout<<mx<<" "<<mn<<endl;
    return mx-mn;
}

int k;
    int f(int i,int a[],vector<int> &dp){
        if(i<0){
            return calc(a);
        }
        
        // if(dp[i]!=-1)return dp[i];
        
        a[i]+=k;
        int inc=f(i-1,a,dp);
        a[i]-=2*k;
        int dec=f(i-1,a,dp);
        a[i]+=k;
        
        return dp[i]= min(inc,dec);
    }
    int getMinDiff(int arr[], int N, int K) {
        // code here
        n=N;
        k=K;
        vector<int> dp(N,-1);
        // return f(n-1,arr,dp);
        sort(arr,arr+n);
       int ans = arr[n-1] - arr[0];
       for(int i=0; i<n-1; i++) {
           int mini = min(arr[0]+k, arr[i+1]-k);
           int maxi = max(arr[i]+k, arr[n-1]-k);
           ans = min(ans, maxi - mini);
       }
       return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends