class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        vector<bool> isPrime(100001, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= 100000; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= 100000; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int ans = 0;

        for (auto n : nums) {
            int cnt = 0;

            for (int i = 2; i * i < n; i++) {
                if (isPrime[i] && n % i == 0) {
                    if (isPrime[n / i] || i * i * i == n) {
                        ans += (1 + n + i + (n / i));
                    }
                }
            }
        }

        return ans;
    }
};