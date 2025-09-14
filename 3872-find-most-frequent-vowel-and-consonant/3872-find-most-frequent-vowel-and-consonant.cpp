class Solution {
public:
    int maxFreqSum(string s) {
        int consonant_max = 0, vowel_max = 0;
        unordered_map<char, int> cnt;

        for (char c : s) {
            cnt[c]++;
        }

        for (const auto& [key, value] : cnt) {
            if (key == 'a' || key == 'e' || key == 'i' || key =='o' || key =='u') {
                vowel_max = max(vowel_max, value);
            }
            else
            {
                consonant_max = max(consonant_max, value);
            }
        }

        return consonant_max + vowel_max;
    }
};