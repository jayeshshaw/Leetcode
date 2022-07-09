class Solution {
public:
    int compress(vector<char>& v) {
        int n=v.size();
        string s="";
        int i;
        for(i=0;i<n;){
            int k=0;
            char c =v[i];
            while(i<n && v[i]==c){k++;i++;}
            s+=c;
            if(k>1)s+=to_string(k);
        }
        // cout<<s;
        vector<char> ans;
        for(auto i: s)ans.push_back(i);
        v=ans;
        return s.size();
    }
};