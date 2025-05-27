class Solution {
public:
    int differenceOfSums(int n, int m) {
        int total = (n + 1) * n / 2;
        int a = 0;

        for (int i = 1; i * m <= n; i++)
        {
            a += m * i;
        }

        return total - 2 * a;
    }
};