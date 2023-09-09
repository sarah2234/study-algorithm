class Solution {
    public int combinationSum4(int[] nums, int target) {
        // dp 문젠가?
        // nums -  element해서 남은 걸로 또 recurssion
        // 0이 되면 cnt+1
        int[] dp = new int[target + 1];
        Arrays.fill(dp, -1);
        
        return recur(nums, target, dp);
    }
    
    int recur(int[] nums, int target, int[] dp) {
        if (target == 0) 
            return 1;
        else if (target < 0) 
            return 0;
        
        
        if (dp[target] != -1)
            return dp[target];
            
        int cnt = 0;
        for (int num : nums) {
            if (target - num >= 0) {
                cnt += recur(nums, target - num, dp);
            }     
        }
        
        dp[target] = cnt;
        return cnt;
    }
}