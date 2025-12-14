class Solution {
public:
    int numberOfWays(string corridor) {
        long long ans = 1;
        int cnt = 0;
        const int MOD = 1'000'000'007; // 1e9 + 7
        int lastSeatIndex = 0;
        
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                cnt++;

                if (cnt % 2 == 0) {
                    lastSeatIndex = i;
                } else if (cnt > 1) {
                    ans = (ans * (i - lastSeatIndex)) % MOD;
                    cout << i - lastSeatIndex <<" ";
                }
            }
        }

        if (cnt % 2 == 1 || cnt < 2) {
            ans = 0;
        } else if (ans == 0) {
            ans = 1;
        }

        return ans;
    }
};