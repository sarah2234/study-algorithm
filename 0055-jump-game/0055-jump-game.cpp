class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if (dp[i - 1] > 0) {
                dp[i] = max(dp[i - 1] - 1, nums[i]); // 최대한 많이 올라갈 수 있는 계단 선택
                // 올라갈 수록 dp는 -1 소모
            }
            else{
                dp[i] = -1; // 못 올라감
            }
        }
        if(dp[nums.size()-1]!=-1){
            return true;
        }
        return false;
    }
};