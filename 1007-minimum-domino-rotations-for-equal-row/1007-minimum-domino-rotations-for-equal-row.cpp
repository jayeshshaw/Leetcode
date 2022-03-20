class Solution {
public:
    int minDominoRotations(vector<int>& t, vector<int>& bb) {
        // map<int,vector<int>> m1,m2;
        // for(int i=0;i<t.size();i++)m1[t[i]].push_back(i);
        // for(int i=0;i<b.size();i++)m2[b[i]].push_back(i);
        int n=t.size(),a=0,b=0;
        for(int i=0;i<n && (t[0]==t[i] || t[0]==bb[i]);i++){
            if(t[0]!=t[i])a++;
            if(t[0]!=bb[i])b++;
            if(i==n-1)return min(a,b);
        }
        a=0,b=0;
        for(int i=0;i<n && (bb[0]==t[i] || bb[0]==bb[i]);i++){
            if(bb[0]!=t[i])a++;
            if(bb[0]!=bb[i])b++;
            if(i==n-1)return min(a,b);
        }
        return -1;
    }
};