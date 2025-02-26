class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int current_max = nums[0];
        int global_max = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            current_max = std::max(nums[i], current_max + nums[i]);
            global_max = std::max(global_max, current_max);
        }

        int current_min = nums[0];
        int global_min = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            current_min = std::min(nums[i], nums[i] + current_min);
            global_min = std::min(global_min, current_min);
        }

        return max(global_max, abs(global_min));
    }
};