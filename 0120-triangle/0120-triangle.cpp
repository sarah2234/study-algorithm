class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> memo (n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            memo[n - 1][i] = triangle[n - 1][i];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                memo[i][j] = triangle[i][j] + min(memo[i + 1][j], memo[i + 1][j + 1]);
            }
        }

        return memo[0][0];
    }
};