class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        // 1. prefix sum (m+1 x n+1)
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] =
                    prefix[i - 1][j]
                  + prefix[i][j - 1]
                  - prefix[i - 1][j - 1]
                  + mat[i - 1][j - 1];
            }
        }

        // 2. binary search on side length
        int left = 1, right = min(m, n);
        int ans = 0;

        while (left <= right) {
            int k = (left + right) / 2;
            bool ok = false;

            // check if any k x k square is valid
            for (int i = 0; i + k <= m && !ok; i++) {
                for (int j = 0; j + k <= n; j++) {
                    int sum =
                        prefix[i + k][j + k]
                      - prefix[i][j + k]
                      - prefix[i + k][j]
                      + prefix[i][j];

                    if (sum <= threshold) {
                        ok = true;
                        break;
                    }
                }
            }

            if (ok) {
                ans = k;
                left = k + 1;   // try bigger square
            } else {
                right = k - 1; // try smaller square
            }
        }

        return ans;
    }
};
