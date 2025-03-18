class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0;
        int start = 0, end = 0;
        int bitMask = 0; // 현재 subarray의 모든 숫자의 OR 결과

        while (end < nums.size()) {
            // 새로운 숫자를 추가할 때, AND 연산 결과가 0이 아니면 겹치는 비트가 있는 것
            while ((bitMask & nums[end]) != 0) {
                // start를 이동하면서 bitMask에서 해당 숫자를 제거
                bitMask ^= nums[start];
                start++;
            }

            // 새로운 숫자를 추가
            bitMask |= nums[end];
            ans = max(ans, end - start + 1);
            end++;
        }

        return ans;
    }
};
