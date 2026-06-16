class Solution {
public:
    string processStr(string s) {
        string ans = "";
        
        for (char c : s) {
            switch (c) {
                case '*' :
                    if (!ans.empty()) {
                        ans.pop_back();
                    }
                    break;
                case '#' :
                    ans += ans;
                    break;
                case '%' :
                    reverse(ans.begin(), ans.end());
                    break;
                default :
                    ans += c;
                    break;
            }
        }
        
        return ans;
    }
};