class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int quadruplets = 0;
        
        for(int a = 0; a + 3 < nums.size(); a++)
        {
            for(int b = a + 1; b + 2 < nums.size(); b++)
            {
                for(int c = b + 1; c + 1 < nums.size(); c++)
                {
                    for(int d = c + 1; d < nums.size(); d++)
                    {
                        if((nums[a]+nums[b]+nums[c])==nums[d])
                            quadruplets++;
                    }
                }
            }
        }
        
        return quadruplets;
    }
};