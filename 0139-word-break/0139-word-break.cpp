class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        int max_len = 0;
        for (auto word : wordDict)
        {
            max_len = max(max_len, static_cast<int>(word.size()));
        }
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = i - 1; j >= std::max(i - max_len - 1, 0); j--) 
            {
                if (dp[j] && std::find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};