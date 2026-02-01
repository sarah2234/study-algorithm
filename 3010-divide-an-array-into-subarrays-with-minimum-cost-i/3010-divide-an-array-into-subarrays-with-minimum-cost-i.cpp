class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = nums[0];
        vector<int> copiedNums(nums.begin() + 1, nums.end());

        sort(copiedNums.begin(), copiedNums.end());
        ans += copiedNums[0] + copiedNums[1];

        return ans;
    }
};