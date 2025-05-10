class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int cnt_1 = 0, cnt_2 = 0;
        long long sum_1 = 0, sum_2 = 0;

        for (auto num : nums1)
        {
            if (num == 0) cnt_1++;
            sum_1 += num;
        }
        
        for (auto num : nums2)
        {
            if (num == 0) cnt_2++;
            sum_2 += num;
        }

        long long total_1 = cnt_1 + sum_1, total_2 = cnt_2 + sum_2;
        if ((cnt_1 == 0 && total_1 < total_2) || (cnt_2 == 0 && total_1 > total_2))
        {
            return -1;
        }

        return max(total_1, total_2);
    }
};