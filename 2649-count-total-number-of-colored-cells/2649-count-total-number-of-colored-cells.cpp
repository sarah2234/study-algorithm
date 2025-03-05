class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1;
        if (n == 1) return ans;

        for (int i = 2; i <= n; i++)
        {
            ans += (i * 2 - 2) * 2;
        }

        return ans;
    }
};