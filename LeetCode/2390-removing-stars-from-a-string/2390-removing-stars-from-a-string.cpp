class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;
        for (char c : s)
        {
            stk.push(c);
            if (c == '*')
            {
                stk.pop();
                stk.pop();
            }
        }
        
        string answer = "";
        while (!stk.empty())
        {
            answer += stk.top();
            stk.pop();
        }
        reverse(answer);
        return answer;
    }
    
    void reverse(string& s)
    {
        int n = s.length();
        for (int i = 0; i < n / 2; i++)
        {
            std::swap(s[i], s[n - i - 1]);
        }
    }
};