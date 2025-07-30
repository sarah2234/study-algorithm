class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> ans;
        vector<int> lastSeen(30, -1);

        for (int left = nums.size() - 1; left >=0; left--) {
            bitset<30> bit(nums[left]);
            int right = left;

            for (int i = 0; i < 30; i++) {
                if (bit[i]) {
                    lastSeen[i] = left;
                }
                right = max(right, lastSeen[i]);
            }

            ans.emplace_back(right - left + 1);
        }

        std::reverse(ans.begin(), ans.end());

        return ans;
    }
};