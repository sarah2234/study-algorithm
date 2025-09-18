class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        istringstream iss(text); // 스트림으로 변환
        vector<string> textTokens;
        string word;
        set<char> brokenLettersSet;
        int ans = 0;

        while (iss >> word) { // 공백 단위로 잘라서 word에 저장
            textTokens.emplace_back(word);
        }

        for (char &c : brokenLetters) {
            brokenLettersSet.insert(c);
        }

        for (string &token : textTokens) {
            bool broken = false;

            for (char &c : token) {
                if (brokenLettersSet.count(c)) {
                    broken = true;
                    break;
                }
            }

            if (!broken) ans++;
        }

        return ans;
    }
};