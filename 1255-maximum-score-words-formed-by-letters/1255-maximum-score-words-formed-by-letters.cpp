class Solution {
public:
    
    int f(int ind,string s,vector<string>& words,unordered_map<char,int> &avail,  vector<int>& score){
        
        if(ind==words.size()){
            unordered_map<char,int> mp;
            int score_here=0;
            for(auto i: s){score_here+=score[i-'a']; mp[i]++;if(mp[i]>avail[i])return 0;}
            return score_here;
        }
        
        int pick=f(ind+1,s+words[ind],words,avail,score);
        int notpick=f(ind+1,s,words,avail,score);
        return max(pick,notpick);
        
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int> avail;
        for(auto i: letters)avail[i]++;
        
        return f(0,"",words,avail,score);
    }
};