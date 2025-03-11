class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int left = 0, right = 0;
        unordered_map<char, int> abc;

        while (right < s.size())
        {
            abc[s[right]]++;

            while (abc.size() == 3)
            {
                ans += s.size() - right;
                abc[s[left]]--;

                if (abc[s[left]] == 0)
                {
                    abc.erase(s[left]);
                }

                left++;
            }

            right++;
        }

        return ans;
    }
};