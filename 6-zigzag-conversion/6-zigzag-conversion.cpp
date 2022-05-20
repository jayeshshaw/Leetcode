class Solution {
public:
    string convert(string s, int n) {
        if(n>=s.size())return s;
        if(n==1)return s;
        // int k=row/2;
        // string asn1=s[0],ans2=s[row-1];
        // int a=n-1+n-2;b=n-1+n-2;
        // while(k>0){
        //     ans1+=s[a]
        //     k--;
        // }
        vector<string>a(n);
        string ans;
        int i,j=0,k;
        for(i=0;i<s.length();)        {
            k=i;
            while(i<s.length() && i<k+n-1)
                a[j++].push_back(s[i++]);
            
            k=i;
            while(i<s.length() && i<k+n-1)
                a[j--].push_back(s[i++]);
            
        }
        // for(auto i: a)cout<<i<<endl;
        for(int i=0;i<n;i++)ans+=(a[i]);
        
        return ans; 
    }
};