class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> memo(n);
        
        for (int i = n - 1; i >= 0; i--) {
            int next = i + 1 + questions[i][1];
            long long solve = questions[i][0] + (next < n ? memo[next] : 0);
            long long skip = i == n - 1 ? 0 : memo[i + 1];
            memo[i] = max(solve, skip);
        }

        return memo[0];
    } 
};