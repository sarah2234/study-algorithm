class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        long long len = 1; 

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] - 1 == prices[i]) {
                len++;
            } else {
                ans += len * (len + 1) / 2;
                len = 1;
            }
        }

        ans += len * (len + 1) / 2;
        return ans;
    }
};
