for(int i=v.size()-1;i>=0;i--){
for(int pre=i-1;pre>=-1;pre--){
int a=0,b=0;
if(pre==-1 || v[i]> v[pre])a= 1 + next[i+1];
b=next[pre+1];
​
cur[pre+1]= max(a,b);
}
next=cur;
}
return cur[0];
// return f(0,-1,v,dp);
}
};
​
​
​
​
​
​
​
​
​
​
​
​
​
​
​
​
​
​
​
​
vector<int> help;
help.push_back(v[0]);
for(int i=1;i<v.size();i++){
if(v[i]>help[help.size()-1])help.push_back(v[i]);
else{
int ind=lower_bound(help.begin(),help.end(),v[i])-help.begin();
help[ind]=v[i];
}
}
return help.size();
```