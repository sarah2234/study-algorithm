class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int total_area = (ax2-ax1)*(ay2-ay1)+(bx2-bx1)*(by2-by1);
        int overlapping_x1 = max(ax1, bx1);
        int overlapping_x2 = min(ax2, bx2);
        int overlapping_y1 = max(ay1, by1);
        int overlapping_y2 = min(ay2, by2);
        //cout<<overlapping_x1<<" "<<overlapping_y1<<" "<<overlapping_x2<<" "<<overlapping_y2<<endl;
        
        // 안 겹침
        if(overlapping_x1 > overlapping_x2 ||  overlapping_y1 > overlapping_y2)
        {
            //cout<<"안 겹침";
            return total_area;
        }
        // 부분적으로 겸치기
        else if(overlapping_x1 >= ax1 && overlapping_x2 <= ax2 && overlapping_y1 >= ay1 && overlapping_y2 <= ay2)
        {
            total_area = total_area - (overlapping_x2-overlapping_x1)*(overlapping_y2-overlapping_y1);
            //cout<<"부분적으로 겹치기";
        }
        
        // 아예 겹치기
        else if(overlapping_x1 == ax1 && overlapping_x2 == ax2 && overlapping_y1 == ay1 && overlapping_y2 == ay2)
        {
            //cout<<"아예 겹침(a)";
            total_area = total_area - (ax2-ax1)*(ay2-ay1);
        }
        else if(overlapping_x1 == bx1 && overlapping_x2 == bx2 && overlapping_y1 == by1 && overlapping_y2 == by2)
        {
            //cout<<"아예 겹침(b)";
            total_area = total_area - (bx2-bx1)*(by2-by1);
        }
        
        
        return total_area;
    }
};