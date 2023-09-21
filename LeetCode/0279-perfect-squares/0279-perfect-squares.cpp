class Solution {
public:
    int dp[100001];
        
    int numSquares(int n) {
        for(int i = 0; i <= n; i++)
        {
            dp[i] = i;
        }
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - j  * j] + 1);
            }
        }
        return dp[n];
    }
};