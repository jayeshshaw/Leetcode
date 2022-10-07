class Solution {

private:
    string make(int n){
        string ans="";
        for(int i=0;i<8;i++){
            if(n&(1<<i))ans.push_back('1');
            else ans.push_back('0');
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
public:
    bool validUtf8(vector<int>& data) {
        vector<string> v;
        for(auto i: data){
            string s=make(i);
            // cout<<s<<" ";
            v.push_back(s);
        }
        for(int i=0;i<v.size();){
            if(v[i][0]=='0'){i++;continue;}
            string abhi=v[i];
            int ones=0;
            int j=0;
            while(abhi[j]=='1')j++,ones++;
            if(ones==1 || ones>4)return 0;
            ones--;i++;
            while(ones-- && i<v.size()){
                if(!(v[i][0]=='1' && v[i][1]=='0'))return 0;
                i++;
            }
            if(ones>0)return 0;
        }
        return 1;
    }
};