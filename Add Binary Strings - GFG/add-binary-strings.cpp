//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string a, string b)
	{
	     string ans="";
        int i=a.size()-1,j=b.size()-1;
        int c=0;
        
        while(i>=0 || j>=0 || c>0){
            if(i>=0)c+=a[i]-'0';
            if(j>=0)c+=b[j]-'0';
            ans+=(c%2)+'0';c/=2;
            i--;j--;
        }
        reverse(ans.begin(),ans.end());
        string s;
        i=0;
        while(i<ans.size() && ans[i]=='0')i++;
        while(i<ans.size())s.push_back(ans[i++]);
        return s;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends