```
vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
vector<string> ans;
for(int i=0;i<words.size();i++){
if(pattern.size()==words[i].size()){
map<char,char> m,mp;
bool hoga=true;
for(int j=0;j<pattern.size();j++){
if(m.find(pattern[j])==m.end())
m[pattern[j]]=words[i][j];
if(mp.find(words[i][j])==mp.end())
mp[words[i][j]]=pattern[j];
if(m[pattern[j]]!=words[i][j]){hoga=false;}
if(mp[words[i][j]]!=pattern[j]){hoga=false;}
}
if(hoga)ans.push_back(words[i]);
}
}
return ans;
}
```