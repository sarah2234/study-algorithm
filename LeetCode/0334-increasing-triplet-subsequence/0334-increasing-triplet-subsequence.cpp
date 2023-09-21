class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int baseNum = nums[0];
        int secondBiggestNum = INT_MAX;
        
        for(int i = 1; i != nums.size(); i++)
        {
            if(baseNum > nums[i])
                baseNum = nums[i];
            else if(nums[i] > secondBiggestNum)
                return true;
            else if(baseNum < nums[i] && nums[i] < secondBiggestNum)
                secondBiggestNum = nums[i];
        }
        return false;
    }
};