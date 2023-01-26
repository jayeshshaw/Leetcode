//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{   
    private:
    bool cases(char c){
        return islower(c);
    }
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string s, int n)
    {
        string p=s;
        sort(begin(p),end(p));
        int a=0,b;
        for(int i=0;i<n;i++){
            if(cases(p[0]) !=cases(p[i]) ){
                b=i;break;
            }
        }
        // cout<<p<<" ";
        // if(cases(s[0]))swap(a,b);
        string ans="";
        for(int i=0;i<n;i++){
            if(!cases(s[i]))ans+=p[a++];
            else ans+=p[b++];
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
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends