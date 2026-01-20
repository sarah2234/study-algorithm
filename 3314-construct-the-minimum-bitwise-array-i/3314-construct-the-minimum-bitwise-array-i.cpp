class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int n : nums) {
            bool found = false;
            for (int i = 1; i < n; i++) {
                if (((i + 1) | i) == n) {
                    ans.push_back(i);
                    found = true;
                    break;
                }
            }

            if (!found) {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};