class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";
        stack<int> openBracketIndices;

        for (const char& c : s) {
            if (c == '(') {
                openBracketIndices.push(ans.size());
            } else if (c == ')') {
                int start = openBracketIndices.top();
                openBracketIndices.pop();
                reverse(ans.begin() + start, ans.end());
            } else {
                ans += c;
            }
        }

        return ans;
    }
};