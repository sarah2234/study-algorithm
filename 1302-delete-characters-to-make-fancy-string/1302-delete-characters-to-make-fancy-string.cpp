class Solution {
public:
    string makeFancyString(string s) {
        int count = 1;
        char c = s[0];
        string result{s[0]};

        for (int i = 1; i < s.size(); i++) {
            if (c == s[i]) {
                count++;

                if (count < 3) {
                    result += s[i];
                } 
            } else {
                c = s[i];
                count = 1;
                result += s[i];
            }
        }

        return result;
    }
};