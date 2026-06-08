class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        if (n == 1) return nums;

        vector<int> biggerNums(n);
        int left = 0, right = 0;

        for (auto num : nums) {
            nums[left] = biggerNums[right] = num;
            left += (num < pivot);
            right += (num > pivot);
        }

        int numOfPivot = n - left - right;
        auto it_pivot = nums.begin() + left;

        fill(it_pivot, it_pivot + numOfPivot, pivot);
        copy(biggerNums.begin(), biggerNums.begin() + right, it_pivot + numOfPivot);

        return nums;
    }
};