//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        // code here 
        int start=0,end=0,ans=0,oranges=0;
        while(end<n){
            if(arr[end]=='O'){
                oranges++;
                if(oranges>m){
                    while(start<end && arr[start]=='A')start++;
                    start++;
                }
                ans=max(ans,end-start+1);
            }
            else{
                ans=max(ans,end-start+1);
            }
            
            end++;
            
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends