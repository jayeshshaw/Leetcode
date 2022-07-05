// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    bool already=true;
	    for(int i=1;i<n;i++){
	        if(arr[i]<arr[i-1]){already=false;break;}
	    }
	    if(already)return 0;
	    // code here
	    int l=0;
	    int e=n-1;
	    int mid=l+(e-l)/2;
	    while(l<=e)
	    {   
	        mid=l+(e-l)/2;
	        if(arr[mid]>arr[mid+1])
	        return mid+1;
	        
	        else if(arr[mid]>=arr[0])
	        l=mid+1;
	        
	        else if(arr[mid]<=arr[e])
	        e=mid-1;
	        
	    }
	    return mid+1;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends