class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        bool arr = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (!arr && nums[i] == 1)
            {
                int length = 1;
                arr = true;
                int zeroCnt = 0;
                //cout << "start: " << i << endl;
                int j = i + 1;
                for (; j < n; j++)
                {
                    if (nums[j] == 1)
                    {
                        length++;
                    }
                    else
                    {
                        if (zeroCnt == 0)
                            zeroCnt = 1;
                        else
                        {
                            //cout << "end: " << j << endl;
                            break;
                        }
                    }
                }
                if (i == 0 && j == n)
                    return n - 1;
                ans = max(length, ans);
                //cout << endl;
            }
            else if (nums[i] == 0)
            {
                arr = false;
            }
        }
        return ans;
    }
};