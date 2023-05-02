class Solution {
public:
    int arraySign(vector<int>& nums) {
        double product = 1;
        int ans = 0;
        for (auto num : nums)
        {
            product *= num;
        }
        
        if (product > 0)
            ans = 1;
        else if (product < 0)
            ans = -1;
        return ans;
    }
};