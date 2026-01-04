class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int maxN = 1;
        for (int n : nums) maxN = max(maxN, n);

        vector<bool> isPrime(maxN + 1, true);
        isPrime[0] = isPrime[1] = false;

        // 에라토스테네스의 체
        for (int i = 2; i * i <= maxN; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= maxN; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int ans = 0;

        for (int n : nums) {
            for (int i = 2; i * i <= n; i++) {
                if (!isPrime[i]) continue;
                if (n % i != 0) continue;
                
                int j = n / i;

                if (i != j && isPrime[j]) {
                    ans += 1 + i + j + n;
                }
                else if (i * i * i == n) {
                    ans += 1 + i + i * i + n;
                }

                break;
            }
        }

        return ans;
    }
};