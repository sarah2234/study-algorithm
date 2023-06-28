class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        int ans[2] = {0, 0};
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true; // i 번째 인덱스 ~ i 번째 인덱스까지 palindrome(한 글자면 palindrome)
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true; // 두 개의 연속된 인덱스가 palindrome일 때 true
                ans[0] = i;
                ans[1] = i + 1;
            }
        }
        
        for (int diff = 2; diff < n; diff++) // 길이 3부터 palindrome인지 체크
        {
            for (int i = 0; i < n - diff; i++)
            {
                int j = i + diff; // diff = j - i
                if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                    ans[0] = i;
                    ans[1] = j;
                }
            }
        }
        
        return s.substr(ans[0], ans[1] - ans[0] + 1);
    }
};