class Solution {
public:

    int houseRobberOne(vector<int>& arr) {
        int N = arr.size();
        if (N == 1) return arr[0];
        vector<int> dp(N, 0);
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        for(int i = 2; i < N; i++){
            dp[i] = max(dp[i-1], dp[i-2] + arr[i]);
        }
        return dp[N-1];
    }

    int rob(vector<int>& nums) {
        int N = nums.size();
        if (N == 1) return nums[0];
        vector<int> v1(nums.begin() + 1, nums.end());
        vector<int> v2(nums.begin(), nums.end() - 1);
        return max(houseRobberOne(v1), houseRobberOne(v2));
    }
};