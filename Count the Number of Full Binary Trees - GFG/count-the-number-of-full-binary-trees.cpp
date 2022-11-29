//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    
    long long int numoffbt(long long int arr[], int n){
        // Finding the minimum and maximum values in
        // given array.
        long long int maxvalue = INT_MIN, minvalue = INT_MAX;
        for (int i = 0; i < n; i++){
            maxvalue = max(maxvalue, arr[i]);
            minvalue = min(minvalue, arr[i]);
        }
     
        long long int mark[maxvalue + 2]={0};
        long long int value[maxvalue + 2]={0};
     
        // Marking the presence of each array element
        // and initialising the number of possible
        // full binary tree for each integer equal
        // to 1 because single node will also
        // contribute as a full binary tree.
        for (int i = 0; i < n; i++){
            mark[arr[i]] = value[arr[i]] = 1;
        }
     
        // From minimum value to maximum value of array
        // finding the number of all possible Full
        // Binary Trees.
        long long int ans = 0, mod=1000000007;
        for (long long int i = minvalue; i <= maxvalue; i++)
        {
            // Find if value present in the array
            if (mark[i])
            {
                // For each multiple of i, less than
                // equal to maximum value of array
                for (int j = i + i; j <= maxvalue && j/i <= i; j += i)
                {
                    // If multiple is not present in the
                    // array then continue.
                    if (!mark[j])
                        continue;
     
                    // Finding the number of possible Full
                    // binary trees for multiple j by
                    // multiplying number of possible Full
                    // binary tree from the number i and
                    // number of possible Full binary tree
                    // from i/j.
                    value[j] = (value[j] + (value[i] * value[j/i]))%mod;
     
                    // Condition for possiblity when left
                    // chid became right child and vice versa.
                    if (i != j/i)
                        value[j] = (value[j] + (value[i] * value[j/i]))%mod;
                }
            }
     
            ans = (ans+value[i])%mod;
        }
     
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<<ob.numoffbt(a,n)<<endl;
		
	}
	return 0;
}


// } Driver Code Ends