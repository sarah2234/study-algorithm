class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 0; i < n + 1; i++) {
            ans[i] = bitset<20>(i).count();
        }
        return ans;
    }
};