class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;

        int mx = 0;
        for (int x : nums) {
            cnt[x]++;
            mx = max(mx, x);
        }

        int ans = 1;

        if (cnt.count(1)) {
            ans = max(ans, cnt[1] % 2 ? cnt[1] : cnt[1] - 1);
        }

        for (auto& [x, _] : cnt) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            while (true) {
                if (!cnt.count(cur)) {
                    len = max(1, (len - 1) * 2 + 1);
                    break;
                }

                if (cnt[cur] == 1) {
                    len = len * 2 + 1;
                    break;
                }

                len++;

                // cur^2가 너무 커지는 것 방지 : curr * curr > mx에서 양변을 curr로 나누기
                if (cur > 1LL * mx / cur) {
                    len = (len - 1) * 2 + 1;
                    break;
                }

                cur *= cur;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};