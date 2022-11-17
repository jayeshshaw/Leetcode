class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        long long area=0;
        area=abs(ax1-ax2)* abs(ay1-ay2);
        area+=abs(bx1-bx2)* abs(by1-by2);
        
        int ox1 = max(ax1,bx1);   // ** left edge of overlapping region
       int oy1 = max(ay1,by1);   // ** bottom edge of overlapping region
       int ox2 = min(ax2,bx2);   // ** right edge of overlapping region
       int oy2 = min(ay2,by2);   // ** top edge of overlapping region

        if(ox2>ox1 && oy2>oy1){
            area -= (abs(ox1-ox2)*abs(oy1-oy2));
        }
        return area;   
        
        
    }
};