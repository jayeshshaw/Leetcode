//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalWays(int n, vector<int>c) {
        sort(begin(c),end(c));
        int mod=1000000007;
        long long int ans=c[0];
        for(int i=n-1;i>0;i--){
            if(c[i]<i)return 0;
            ans=((ans%mod)*(c[i]-i)%mod)%mod;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>capacity(n);
		for(int i = 0; i < n; i++)
			cin >> capacity[i];
		Solution ob;
		int ans = ob.totalWays(n, capacity);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends