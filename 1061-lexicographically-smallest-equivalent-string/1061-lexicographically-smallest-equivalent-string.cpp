class Solution {

private:
    vector<int> p;

    void make(int v){p[v]=v;}

    int find(int x){return (x==p[x]?x:(p[x]=find(p[x])));}

    bool join(int a, int b){
      a=find(a);b=find(b); 
      if(a==b)return 0; 
      if(p[a]<p[b])swap(a,b); 
      p[a]=b;
      return 1;
        
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        p.resize(26,0);
        for(int i=0;i<26;i++)p[i]=i;
        
        int n=s1.size();
        for(int i=0;i<n;i++){
            bool f=join(s1[i]-'a',s2[i]-'a');
        }
        
        string ans="";
        for(auto i: baseStr){
            int k=i-'a';
            ans.push_back(find(k)+'a');
        }
        return ans;
    }
};