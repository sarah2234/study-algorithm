class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int quadruplets = 0;
        
        for(int d = 3; d < nums.size(); d++)
        {
            for(int c = d - 1; c >= 2; c--)
            {
                int left_1 = nums[d] - nums[c];
                for(int b = c - 1; left_1 > 0 && b >= 1; b--)
                {
                    int left_2 = left_1 - nums[b];
                    for(int a = b - 1; left_2 > 0 && a >= 0; a--)
                    {
                        if(left_2 - nums[a] == 0)
                        {
                            quadruplets++;
                        }
                    }
                }
            }
        }
        
        return quadruplets;
    }
};