class Solution {
public:
    int countOdds(int low, int high) {
        //if (high - low == 1)
            //return 1;
        
        int even = 0;
        if (low % 2 == 0)
        {
            low--;
            even = 1;
        }
        if (high % 2 == 0)
        {
            high--;
        }
        return (high - low) / 2 + 1 - even;
    }
};