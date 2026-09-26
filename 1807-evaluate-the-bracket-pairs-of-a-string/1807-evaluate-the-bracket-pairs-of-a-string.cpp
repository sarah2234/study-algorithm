class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string, string> m;

        for (auto k : knowledge) {
            m[k[0]] = k[1];
        }

        string answer = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '(') {
                answer += s[i];
                continue;
            }

            string key = "";

            i++;

            while (s[i] != ')') {
                key += s[i];
                i++;
            }

            if (m.count(key)) {
                answer += m[key];
            } else {
                answer += "?";
            }
        }

        return answer;
    }
};