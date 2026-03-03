class Solution {
public:
    string invert(const string& s) {
        string r = s;
        for (char& c : r)
            c = (c == '0') ? '1' : '0';
        return r;
    }

    string reverseStr(const string& s) {
        string r = s;
        reverse(r.begin(), r.end());
        return r;
    }

    char findKthBit(int n, int k) {
        string s = "0";

        for (int i = 2; i <= n; i++) {
            string temp = s;
            s = s + "1" + reverseStr(invert(temp));
        }

        return s[k - 1];
    }
};