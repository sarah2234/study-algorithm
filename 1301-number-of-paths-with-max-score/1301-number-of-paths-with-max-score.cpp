class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;

        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<int>> cnt(n, vector<int>(n, 0));

        // S에서 시작
        dp[n - 1][n - 1] = 0;
        cnt[n - 1][n - 1] = 1;

        int dx[3] = {-1, 0, -1};
        int dy[3] = {0, -1, -1};

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (board[i][j] == 'X') continue;
                if (dp[i][j] == -1) continue;

                for (int k = 0; k < 3; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni < 0 || nj < 0) continue;
                    if (board[ni][nj] == 'X') continue;

                    int add = 0;
                    if (isdigit(board[ni][nj]))
                        add = board[ni][nj] - '0';

                    int score = dp[i][j] + add;

                    if (score > dp[ni][nj]) {
                        dp[ni][nj] = score;
                        cnt[ni][nj] = cnt[i][j];
                    }
                    else if (score == dp[ni][nj]) {
                        cnt[ni][nj] =
                            (cnt[ni][nj] + cnt[i][j]) % MOD;
                    }
                }
            }
        }

        if (cnt[0][0] == 0)
            return {0, 0};

        return {dp[0][0], cnt[0][0]};
    }
};