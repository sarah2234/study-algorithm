class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;
        char prevChar = word[0];
        for (int i = 1; i < word.length(); i++)
        {
            if (word[i] == prevChar)
            {
                ans++;
            }
            else
            {
                prevChar = word[i];
            }
        }

        return ans;
    }
};