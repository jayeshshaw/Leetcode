class Solution {
    public boolean isSubsequence(String s, String t) {
        int c=0;
        if(s.length()>t.length())
            return false;
        if(s.length()==0)return true;
        for(int i=0;i<t.length() && c<s.length();i++)
        {
           if(s.charAt(c)==t.charAt(i))
               c++;
          
        }
        if(c==s.length())
            return true;
        return false;
    }
}