class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        int size = mat[0].size();
        for (int i = 0; i < size / 2; i++)
        {
            ans += mat[i][i] + mat[i][size - 1 - i];
        }
        for (int i = (size - 1) / 2; i >= 0; i--)
        {
            ans += mat[size - 1 - i][i] + mat[size - 1 - i][size - 1 - i];
            //cout << i << ": " << ans << endl;
        }
        if (size % 2 == 1)
            ans -= mat[size / 2][size / 2];
        
        return ans;
    }
};