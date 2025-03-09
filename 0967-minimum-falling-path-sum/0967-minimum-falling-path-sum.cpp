class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix[0].size();

        for (int row = 1; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                int minVal;
                
                if (col == 0) minVal = min(matrix[row - 1][col], matrix[row - 1][col + 1]);
                else if (col == n - 1) minVal = min(matrix[row - 1][col - 1], matrix[row - 1][col]);
                else 
                {
                    minVal = min(matrix[row - 1][col - 1], matrix[row - 1][col]);
                    minVal = min(minVal, matrix[row - 1][col + 1]);
                }

                matrix[row][col] += minVal;
            }
        }

        int ans = INT_MAX;
        for (auto i : matrix[n - 1]) ans = min(ans, i);

        return ans;
    }
};