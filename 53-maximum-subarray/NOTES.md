O(n2)
```
int ans=0;
for(int i=0;i<n;i++){
int s=0;
for(int j=i;j<n;j++){
s+=a[j];
ans=max(s,ans);
}
}
return ans;
```