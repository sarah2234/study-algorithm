class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        
        int n = pairs.size();
        vector<int> dp(n, 1);
        
        for (int i = 1; i < n; i++) {
            int j = i - 1;
            for (; j >= 0; j--) {
                if (pairs[i][0] > pairs[j][1]) {
                    break;
                }
            }
            
            if (j != -1) {
                dp[i] = dp[j] + 1;
            } else {
                dp[i] = dp[i - 1];
            }
        }
        
        return dp[n - 1];
    }
};