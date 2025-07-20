class Solution {
public:
    bool isValid(string word) {
        bool isVowel = false;
        bool isConsonant = false;
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        if (word.length() < 3) return false;

        for (auto c : word) {
            if (isalpha(c)) {
                if (vowels.count(tolower(c))) {
                    isVowel = true;
                }
                else {
                    isConsonant = true;
                }
            }
            else if (!isdigit(c)) {
                return false;
            }
        }

        return isVowel && isConsonant ? true : false;
    }
};