class Solution {
public:
    const int MOD = 1e9 + 7;

    // 빠른 거듭제곱: base^exp % mod
    long long power(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2; // 짝수 인덱스 개수
        long long oddCount = n / 2;        // 홀수 인덱스 개수

        long long evenWays = power(5, evenCount); // 0,2,4,6,8
        long long oddWays = power(4, oddCount);   // 2,3,5,7

        return (evenWays * oddWays) % MOD;
    }
};
