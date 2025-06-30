class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> numsWithEndingIndex;
        numsWithEndingIndex.emplace_back(-1, -1);
        int currNum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (currNum != nums[i])
            {
                numsWithEndingIndex.emplace_back(currNum, i - 1);
                currNum = nums[i];
            }
        }

        numsWithEndingIndex.emplace_back(currNum, nums.size() - 1);

        int maxLength = 0;
        for (int i = 1; i < numsWithEndingIndex.size() - 1; i++)
        {
            if (numsWithEndingIndex[i].first + 1 == numsWithEndingIndex[i + 1].first)
            {
                maxLength = max(maxLength,
                numsWithEndingIndex[i + 1].second - numsWithEndingIndex[i - 1].second);
            }
        }

        return maxLength;
    }
};