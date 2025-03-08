class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = k;
        int start = 0;

        while (start + k - 1 < blocks.size())
        {
            int cnt = 0;

            for (int i = 0; i < k; i++)
            {
                cnt = (blocks[start + i] == 'W') ? cnt + 1 : cnt;
            }

            ans = min(cnt, ans);
            start++;
        }

        return ans;
    }
};