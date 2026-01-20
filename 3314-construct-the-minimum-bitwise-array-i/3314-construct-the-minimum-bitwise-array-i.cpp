class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        // __builtin_ctz()
        // std::countr_zero() (C++20)

        vector<int> ans;

        for (int n : nums) {
            if ((n & 1) == 0) {
                ans.push_back(-1);
                continue;
            }

            int cntOnes = 0;
            int leftShift = n;

            while (leftShift & 1) {
                cntOnes++;
                leftShift >>= 1;
            }

            ans.push_back(n - (1 << (cntOnes - 1)));
        }

        return ans;
    }
};