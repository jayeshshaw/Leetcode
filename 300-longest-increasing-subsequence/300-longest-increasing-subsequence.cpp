class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
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
    }
};