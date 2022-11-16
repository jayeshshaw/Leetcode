/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int m;
        int l=1,h=n;
        
        while(l<=h){
            m=l+(h-l)/2;
            int res=guess(m);
            if(res==-1)h=m-1;
            else if(res==1)l=m+1;
            else return m;
        }
        return l;
    }
};