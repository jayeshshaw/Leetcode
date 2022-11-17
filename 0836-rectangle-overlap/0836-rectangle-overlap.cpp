class Solution {
public:
    bool isRectangleOverlap(vector<int>& a, vector<int>& b) {
         int ox1 = max(a[0],b[0]);   // ** left edge of overlapping region
         int oy1 = max(a[1],b[1]);   // ** bottom edge of overlapping region
         int ox2 = min(a[2],b[2]);   // ** right edge of overlapping region
         int oy2 = min(a[3],b[3]);   // ** top edge of overlapping region

          if(ox2>ox1 && oy2>oy1){
              return true;
          }
        return 0;
    }
};