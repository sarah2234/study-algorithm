class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        long long cnt_pairs = 0;
        long long ans = 0;
        int start = 0;

        for (int end = 0; end < nums.size(); ++end) {
            cnt_pairs += count[nums[end]];
            count[nums[end]]++;

            while (cnt_pairs >= k) {
                ans += nums.size() - end; 
                count[nums[start]]--;
                cnt_pairs -= count[nums[start]];
                start++;
            }
        }

        return ans;
    }
};
