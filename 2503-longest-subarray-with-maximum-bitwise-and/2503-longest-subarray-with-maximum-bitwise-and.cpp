class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        auto index = max_element(nums.begin(), nums.end());
        auto maxNum = index++;
        int maxLen = 1, currLen = 1;

        for (; index != nums.end(); index++) {
            if (*maxNum == *index) {
                maxLen = max(maxLen, ++currLen);
            } else currLen = 0;
        }

        return maxLen;
    }
};