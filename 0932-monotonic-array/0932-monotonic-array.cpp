class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isIncreasing = false;

        int i = 1;
        for (; i < nums.size(); i++) {
            if (nums[i - 1] < nums[i]) {
                isIncreasing = true;
                break;
            } else if (nums[i - 1] > nums[i]) {
                isIncreasing = false;
                break;
            }
        }

        for (; i < nums.size(); i++) {
            if ((isIncreasing == false && nums[i - 1] < nums[i]) ||
            (isIncreasing == true && nums[i - 1] > nums[i]))
                return false;
        }
        
        return true;
    }
};