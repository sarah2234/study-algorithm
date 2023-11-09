class Solution {
public:
    int countHomogenous(string s) {
        int ans = 0;
        int mod = 1000000007;
        char curr = s[0];
        int cnt = 0;

        for (auto c : s) {
            if (curr == c) {
                ans = (ans + ++cnt) % mod;
            }
            else if (curr != c) {
                ans = (ans + 1) % mod;
                cnt = 1;
                curr = c;
            }
        }

        return ans % mod;
        }
    };
