class Solution {
public:
    int countNumOfPrefix(int n, int prefix) {
        long minPrefix = prefix, maxPrefix = prefix;
        int count = 0;

        while (minPrefix <= n)
        {
            count += min((long)n, maxPrefix) - minPrefix + 1;
            minPrefix *= 10;
            maxPrefix = maxPrefix * 10 + 9;
        }

        return count;
    }

    int findKthNumber(int n, int k) {
        int prefix = 1;
        int count = 1;

        while (count < k)
        {
            int curr = countNumOfPrefix(n, prefix);

            if (count + curr <= k) {
                prefix++;
                count += curr;
            } else {
                prefix *= 10;
                count++;
            }
        }

        return prefix;
    }
};