class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        long long firstIndex = 0, lastIndex = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] - 1 == prices[i]) {
                lastIndex = i;
            } else {
                if (firstIndex == lastIndex) {
                    ans++;
                } else {
                    ans += (lastIndex - firstIndex + 2) * (lastIndex - firstIndex + 1) / 2;
                }

                firstIndex = lastIndex = i;
            }
        }

        if (firstIndex == lastIndex) {
            ans++;
        } else {
            ans += (lastIndex - firstIndex + 2) * (lastIndex - firstIndex + 1) / 2;
        }

        return ans;
    }
};