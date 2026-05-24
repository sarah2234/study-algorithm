class Solution {
public:
    bool check(vector<int>& nums) {
        int index = -1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            return true;
        }

        for (int i = index; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }

        if (nums[nums.size() - 1] > nums[0]) {
            return false;
        }

        return true;
    }
};