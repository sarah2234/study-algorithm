class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int total = 1 << n;

        for (int mask = 0; mask < total; mask++)
        {
            vector<int> subset;

            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                {
                    subset.emplace_back(nums[i]);
                }
            }

            int x = 0;
            for (auto s : subset)
            {
                x ^= s;
            }

            ans += x;
        }

        return ans;
    }
};