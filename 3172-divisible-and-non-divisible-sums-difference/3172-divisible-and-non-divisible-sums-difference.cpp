class Solution {
public:
    int differenceOfSums(int n, int m) {
        int total = (n + 1) * n / 2;
        int k = n / m;

        return total - 2 * ((k + 1) * k / 2 * m);
    }
};