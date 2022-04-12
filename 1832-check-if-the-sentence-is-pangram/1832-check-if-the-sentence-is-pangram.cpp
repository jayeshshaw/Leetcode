class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> m;
       
       for(int i=0;i<sentence.size();i++)
       {
           m.insert(sentence[i]);
       }
        if(m.size()==26)return true;
        else return false;
    }
};