class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)
         return n;
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1; // n이 1일 때 방법은 1가지
        dp[2]=2; // n이 2일 때 방법은 2가지
        for(int i=3;i<=n;i++)
         dp[i]=dp[i-1]+dp[i-2]; // n일 때 1. (n - 1)에서 +1 하는 방법  2. (n - 2)에서 +2 하는 방법
        
        return dp[n];
    }
};