class Solution {
public:
    string clearStars(string s) {
        vector<char> result;
        multiset<int> indices[26];  

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            if (c == '*') {
                for (int j = 0; j < 26; ++j) {
                    if (!indices[j].empty()) {
                        int idx = *indices[j].rbegin();  
                        result[idx] = '#'; // 제거 표시
                        indices[j].erase(--indices[j].end());
                        break;
                    }
                }
            } else {
                result.push_back(c);
                indices[c - 'a'].insert(result.size() - 1);
            }
        }


        string finalStr;
        for (char c : result) {
            if (c != '#') finalStr += c;
        }
        
    return finalStr;
    }
};