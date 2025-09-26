class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;

        for (int i = nums.size() - 1; i - 2 >= 0 ; i--) {
            int leftIndex = 0, rightIndex = i - 1;

            while (leftIndex < rightIndex) {
                if (nums[leftIndex] + nums[rightIndex] > nums[i]) {
                    ans += rightIndex - leftIndex;
                    rightIndex--;
                } else {
                    leftIndex++;
                }
            }
        }
        return ans;
    }
};