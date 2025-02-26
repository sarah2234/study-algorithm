class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int prefixSum = 0;
        int minPrefixSum = 0;
        int maxPrefixSum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            minPrefixSum = min(prefixSum, minPrefixSum);
            maxPrefixSum = max(prefixSum, maxPrefixSum);
        }

        return maxPrefixSum - minPrefixSum;
    }
};