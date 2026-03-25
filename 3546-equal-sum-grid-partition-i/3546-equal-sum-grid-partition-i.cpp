class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total = 0;
        int m = grid.size(), n = grid[0].size();
        long long curr = 0;

        for (auto& row : grid)
            for (int x : row)
                total += x;

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                curr += grid[i][j];
            }

            if (curr * 2 == total) return true;
        }

        curr = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                curr += grid[i][j];
            }

            if (curr * 2 == total) return true;
        }

        return false;
    }
};