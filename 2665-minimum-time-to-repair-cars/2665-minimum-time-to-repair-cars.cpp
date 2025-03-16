class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(), ranks.end()); 
        long long minTime = 0, maxTime = 1LL * ranks[0] * cars * cars;
        long long ans = maxTime;

        while (minTime < maxTime) {
            long long curTime = (minTime + maxTime) / 2;
            long long carCount = 0;

            for (int rank : ranks) {
                carCount += sqrt(curTime / rank);
                if (carCount >= cars) break;
            }

            if (carCount >= cars) {
                ans = curTime; // 가능한 최소 시간 갱신
                maxTime = curTime;
            } else {
                minTime = curTime + 1;
            }
        }

        return ans;
    }
};
