class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int ans = 0;

        for (int i = 0; i + 2 < row; i++) {
            for (int j = 0; j + 2 < col; j++) {
                if (grid[i + 1][j + 1] != 5) continue;
                
                bool used[10] = {false};
                bool ok = true;

                for (int m = 0; m < 3 && ok; m++) {
                    for (int n = 0; n < 3; n++) {
                        int v = grid[i + m][j + n];
                        if (v < 1 || v > 9 || used[v]) {
                            ok = false;
                            continue;
                        }
                        used[v] = true;
                    }
                }
                if (!ok) continue;
                
                if (grid[i][j] + grid[i + 2][j + 2] != 10) continue;
                if (grid[i][j + 2] + grid[i + 2][j] != 10) continue;
                if (grid[i][j + 1] + grid[i + 2][j + 1] != 10) continue;
                if (grid[i + 1][j] + grid[i + 1][j + 2] != 10) continue;

                if (grid[i][j] + grid[i][j + 1] + grid[i][j + 2] != 15) continue;
                if (grid[i][j] + grid[i + 1][j] + grid[i + 2][j] != 15) continue;

                ans++;
            }
        }

        return ans;
    }
};