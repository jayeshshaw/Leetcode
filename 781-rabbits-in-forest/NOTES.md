```
unordered_map<int,int> m;
int ans=0;
for(auto i: a){
if(i==0)ans++;
else{
if(m[i]==0)ans+=i+1;
m[i]++;
if(m[i]==i+1)m[i]=0;
}
}
return ans;
```