class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp(rowIndex + 1, vector<int>());

        for (int i = 0; i <= rowIndex; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) dp[i].push_back(1);
                else {
                    dp[i].push_back(dp[i - 1][j - 1] + dp[i - 1][j]);
                }
            }
        }

        return dp[rowIndex];
    }
};