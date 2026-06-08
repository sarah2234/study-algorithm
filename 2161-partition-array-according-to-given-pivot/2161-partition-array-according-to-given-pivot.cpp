class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left, right, same;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                left.push_back(nums[i]);
            } else if (nums[i] > pivot) {
                right.push_back(nums[i]);
            } else {
                same.push_back(nums[i]);
            }
        }

        vector<int> ans = left;

        ans.insert(ans.end(), same.begin(), same.end());
        ans.insert(ans.end(), right.begin(), right.end());

        return ans;
    }
};