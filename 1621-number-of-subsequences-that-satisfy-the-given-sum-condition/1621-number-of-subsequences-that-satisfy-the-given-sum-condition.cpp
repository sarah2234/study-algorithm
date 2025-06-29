class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int ans = 0;
        int MOD = 1e9 + 7;
        int left = 0, right = nums.size() - 1;
        vector<int> powerOfTwo(nums.size(), 1);
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++)
        {
            powerOfTwo[i] = (powerOfTwo[i - 1] * 2) % MOD;
        }

        
        while (left <= right)
        {
            if (nums[left] + nums[right] <= target)
            {
                ans = (ans + powerOfTwo[right - left]) % MOD;
                left++;
            }
            else
            {
                right--;
            }
        }

        return ans;
    }
};