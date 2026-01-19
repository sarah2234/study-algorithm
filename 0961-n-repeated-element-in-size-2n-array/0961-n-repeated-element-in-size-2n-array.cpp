class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int ans = 0;
        set<int> cnt;

        for (auto n : nums) {
            if (!cnt.count(n)) {
                cnt.insert(n);
            } else {
                ans = n;
                break;
            }
        }

        return ans;
    }
};