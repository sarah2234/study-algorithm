class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        set<int> zeroRows;
        set<int> zeroCols;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    zeroRows.insert(i);
                    zeroCols.insert(j);
                }
            }
        }

        for (auto& row : zeroRows)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[row][i] = 0;
            }
        }

        for (auto& col : zeroCols)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][col] = 0;
            }
        }
    }
};