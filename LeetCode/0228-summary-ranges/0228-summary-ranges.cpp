class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int cnt = 1;
        if (nums.size() == 0)
            return ans;
        
        int a = nums[0], b = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != b + 1)
            {
                if (cnt == 1)
                    ans.push_back(to_string(a));
                else
                    ans.push_back(to_string(a) + "->" + to_string(b));
                a = nums[i];
                cnt = 0;
            }
            b = nums[i];
            cnt++;
        }
        if (a != b)
            ans.push_back(to_string(a) + "->" + to_string(b));
        else
            ans.push_back(to_string(a));
        return ans;
    }
};