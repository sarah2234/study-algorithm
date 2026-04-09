class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int MOD = 1e9 + 7;
        int idx;

        for (auto& q : queries) {
            idx = q[0];

            while (idx <= q[1]) {
                nums[idx] = ((long long)nums[idx] * q[3]) % MOD;
                idx += q[2];
            }

        }

        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            ans ^= nums[i];
        }

        return ans;
    }
};