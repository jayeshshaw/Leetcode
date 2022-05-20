```
vector<string>a(n);
string ans="";
for(int i=0;i<s.length();)
{
int j=0;
int k=i;
while(i<s.length() && i<k+n-1)
{
a[j].push_back(s[i]);
i++;
j++;
}
k=i;
while(i<s.length() && i<k+n-1)
{
a[j].push_back(s[i]);
i++;
j--;
}
}
for(int i=0;i<n;i++)
{
ans.append(a[i]);
}
return ans;
```