class Fancy {
    const long long MOD = 1000000007;
    vector<long long> arr;
    long long add = 0;
    long long mul = 1;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

public:
    Fancy() {}

    void append(int val) {
        long long inv = modPow(mul, MOD - 2);
        long long x = (val - add + MOD) % MOD;
        x = x * inv % MOD;
        arr.push_back(x);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = mul * m % MOD;
        add = add * m % MOD;
    }

    int getIndex(int idx) {
        if (idx >= arr.size()) return -1;
        return (arr[idx] * mul + add) % MOD;
    }
};