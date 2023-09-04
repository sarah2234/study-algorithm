class Solution {
public:
    int myAtoi(string s) {
        int npos = s.find_first_not_of(' ');
        s.erase(0, npos);
        npos = s.find_last_not_of(' ');
        s.erase(npos + 1);
        //s.erase(remove(s.begin(), s.end(), ' '), s.end());
        bool negative = (s[0] == '-' ? true : false);
        
        if (s[0] == '+' || s[0] == '-')
            s.erase(0, 1);
        
        if (isdigit(s[0]) == 0)
            return 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i]) == 0) {
                s.erase(i);
                break;
            }
        }
        
        int ans;
        try {
            ans = stoi(s);
            if (negative)
            ans = -ans;
        } catch (const std::exception& e) {
            if (negative)
                ans = INT_MIN;
            else
                ans = INT_MAX;
        }
        
        return ans;
    }
};