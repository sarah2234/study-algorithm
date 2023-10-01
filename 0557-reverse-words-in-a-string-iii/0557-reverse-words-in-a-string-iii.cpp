class Solution {
public:
    string reverseWords(string s) {
        string ans;
        stack<char> stk;
        for (char c : s) {
            if (c == ' ') {
                while (!stk.empty()) {
                    ans += stk.top();
                    stk.pop();
                }
                ans += ' ';
            } else {
                stk.push(c);
            }
        }

        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }

        return ans;
    }
};