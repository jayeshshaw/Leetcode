class Solution {
public:
    int countOdds(int low, int high) {
        int n=high-low+2;
        return n/2 -(low%2==0 && high%2==0);
    }
};