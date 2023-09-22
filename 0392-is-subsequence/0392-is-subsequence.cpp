class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() == 0)
            return true;

        for (int i = 0, curr = 0; i < t.length(); i++) {
            if (s[curr] == t[i]) {
                if (++curr == s.length()) {
                    return true;
                }
            }
        }

        return false;
    }
};