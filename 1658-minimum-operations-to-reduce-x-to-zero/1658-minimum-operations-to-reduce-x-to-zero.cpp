class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = 0, n = nums.size();
        for (int num : nums) 
            target += num;
        target -= x;
        
        if (target == 0) return n;
        
        int max_len = 0, cur_sum = 0, left = 0;
        
        for (int right = 0; right < n; ++right) {
            cur_sum += nums[right]; // 오른쪽 범위 정하기
            while (left <= right && cur_sum > target) {
                cur_sum -= nums[left]; // 왼쪽 범위 정하기
                left++;
            }
            if (cur_sum == target) {
                max_len = max(max_len, right - left + 1); // maximum subarray의 길이 max_len
            }
        }
        
        return max_len ? n - max_len : -1;
    }
};