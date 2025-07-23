class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int total = 0;

        // x > y 일 때 ab를 먼저 제거
        if (x > y) {
            total += removePattern(s, "ab", x);
            total += removePattern(s, "ba", y);
        } else {
            total += removePattern(s, "ba", y);
            total += removePattern(s, "ab", x);
        }

        return total;
    }

    int removePattern(string& s, const string& pattern, int point) {
        stack<char> stk;
        int score = 0;

        for (char c : s) {
            if (!stk.empty() && stk.top() == pattern[0] && c == pattern[1]) {
                stk.pop(); // pattern[0]과 pattern[1] 짝을 제거
                score += point;
            } else {
                stk.push(c);
            }
        }

        // 스택에 남은 문자들을 다시 문자열로 복원
        string remaining;
        while (!stk.empty()) {
            remaining += stk.top();
            stk.pop();
        }
        reverse(remaining.begin(), remaining.end());
        s = remaining;

        return score;
    }
};
