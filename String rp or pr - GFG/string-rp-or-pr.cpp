//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
private:
    long long pr(string &s,int val){
        stack<char> st;
        long long ans=0;
        for(int i=0;i<s.size();i++){
            if(st.size()==0||s[i]!='r'){
                st.push(s[i]);continue;
            }
            
            if(st.top()== 'p' ){
                st.pop();
                ans+=val;
            }
            else st.push(s[i]);
        }
        s.resize(0);
        while(st.size()>0){
            s.push_back(st.top());
            st.pop();
        }
        reverse(begin(s),end(s));
        return ans;
    }
    
    long long rp(string &s,int val){
        stack<char> st;
        long long ans=0;
        for(int i=0;i<s.size();i++){
            if(st.size()==0||s[i]!='p'){
                st.push(s[i]);continue;
            }
            
            if(st.top()== 'r' ){
                st.pop();
                ans+=val;
                
            }
            else st.push(s[i]);
        }
        s.resize(0);
        while(st.size()>0){
            s.push_back(st.top());
            st.pop();
        }
        reverse(begin(s),end(s));
        return ans;
    }
    
public:
    long long solve(int X,int Y,string s){
      long long ans=0;
      if(X>Y){
          ans+=pr(s,X);
          ans+=rp(s,Y);
      }
      else{
          ans+=rp(s,Y);
        //   cout<<s<<" ";
          ans+=pr(s,X);
      }
      return ans;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends