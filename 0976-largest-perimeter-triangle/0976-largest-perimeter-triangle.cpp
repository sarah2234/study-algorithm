class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int perimeter = 0;
        sort(nums.rbegin(), nums.rend());
        for (int a = 0; a < nums.size() - 2; a++)
        {
            if (nums[a + 2] + nums[a + 1] > nums[a])
                return nums[a] + nums[a + 1] + nums[a + 2];
        }
        
        return 0;
    }
};