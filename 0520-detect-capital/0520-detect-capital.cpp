class Solution {
public:
    bool detectCapitalUse(string word) {
        int c=0;
        for(int i=0;i<word.size();i++){
            if(iscap(word[i]))c++;
        }
        if(c==0|| c==word.size() || (c==1 && iscap(word[0])))return true;
        return false;
    }
    bool iscap(char c){
        return (c>=65 && c<=91);
    }
};