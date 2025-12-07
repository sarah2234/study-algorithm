class Solution {
public:
    int countOdds(int low, int high) {
        int ans = 0;

        if (high % 2 == 1 && low % 2 == 1) ans++;
        
        ans += (high - low + 1) / 2;

        return ans;
    }
};