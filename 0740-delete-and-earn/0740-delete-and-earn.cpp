class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int i : nums) freq[i]++;

        vector<int> noDup;
        for (auto i : freq) noDup.push_back(i.first);
        sort(noDup.begin(), noDup.end());

        vector<int> dp(noDup.size() + 1);
        for (int i = noDup.size()- 1; i >= 0; i--)
        {
            int exclude = dp[i + 1];
            int include = freq[noDup[i]] * noDup[i];

            if (i + 1 < noDup.size())
            {
                if (noDup[i] + 1 == noDup[i + 1]) include += dp[i + 2];
                else include += dp[i + 1];
            }

            dp[i] = max(exclude, include);
        }

        return dp[0];
    }
};