class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        int tmp;
        while (mid <= high)
        {
            switch (nums[mid])
            {
                case 0:
                    tmp = nums[low];
                    nums[low++] = 0;
                    nums[mid++] = tmp;
                    break;
                case 1:
                    mid++;
                    break;
                case 2: 
                    tmp = nums[high];
                    nums[high--] = 2;
                    nums[mid] = tmp;
                    break;
            }
        }
    }
};