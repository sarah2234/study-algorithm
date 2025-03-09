class Solution {
public:
    int numTrees(int n) {
        vector<int> dp;
        dp.push_back(1); // 0
        dp.push_back(1); // 1

        for (int i = 2; i <= n; i++)
        {
            int val = 0;
            for (int node = 0; node <= i - 1; node++)
            {
                int left = node;
                int right = i - 1 - node;

                val += (dp[left] * dp[right]);
            }
            dp.push_back(val);
        }

        return dp[n];
    }
};