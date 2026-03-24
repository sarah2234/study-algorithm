class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        const int MOD = 12345;
        vector<long long> nums;

        for (auto& row : grid) {
            for (auto& val : row) {
                nums.push_back(val);
            }
        }

        vector<long long> prefix(n * m, 1), suffix(n * m, 1);

        for (int i = 1; i < n * m; i++) {
            prefix[i] = (prefix[i - 1] * nums[i - 1]) % MOD;
        }

        for (int i = n * m - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * nums[i + 1]) % MOD;
        }

        vector<vector<int>> ans(n, vector<int>(m));

        for (int i = 0; i < n * m; i++) {
            long long val = (prefix[i] * suffix[i]) % 12345;
            ans[i / m][i % m] = val;
        }

        return ans;
    }
};