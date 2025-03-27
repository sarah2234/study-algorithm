class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int ans = -1;
        unordered_map<int, int> freqMap;

        for (auto num : nums)
        {
            freqMap[num]++;
        }

        int maxFreq = 0;
        for (auto freq : freqMap)
        {
            if (freq.second > freqMap[maxFreq])
            {
                maxFreq = freq.first;
            }
        }

        if (freqMap[maxFreq] * 2 - 1 == nums.size())
            return ans;

        vector<int> cnts(nums.size(), 0);
        if (nums[0] == maxFreq)
            cnts[0] = 1;
        else
            cnts[0] = -1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == maxFreq)
                cnts[i] = cnts[i - 1] + 1;
            else
                cnts[i] = cnts[i - 1] - 1;
        }

        for (int i = 0; i < cnts.size() - 1; i++)
        {
            //cout << cnts[i] << " ";
            if (cnts[i] == 1 && (cnts[cnts.size() - 1] - (cnts[i + 1] - cnts[i])) > 0)
            {
                ans = i;
                break;
            }
        }

        return ans;
    }
};