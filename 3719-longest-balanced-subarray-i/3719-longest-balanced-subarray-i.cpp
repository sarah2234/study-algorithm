class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            unordered_set<int> odds;
            unordered_set<int> evens;

            for (int j = i; j < nums.size(); j++) {
                if (nums[j] & 1) odds.insert(nums[j]);
                else evens.insert(nums[j]);

                if (odds.size() == evens.size()) {
                    ans = max(ans, j - i + 1);
                }
            }
            
        }
        return ans;
    }
};