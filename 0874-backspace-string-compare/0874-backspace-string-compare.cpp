class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string _s = "", _t = "";
        for (auto& c : s) {
            if (c == '#') {
                if (_s != "")
                    _s.pop_back();
            }    
            else
                _s += c;
        }

        for (auto& c : t) {
            if (c == '#') {
                if (_t != "") 
                    _t.pop_back();
            }   
            else
                _t += c;
        }

        return _s.compare(_t) == 0 ? true : false;
    }
};