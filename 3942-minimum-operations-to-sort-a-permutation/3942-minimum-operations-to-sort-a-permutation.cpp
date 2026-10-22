class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = find(nums.begin(), nums.end(), 0) - nums.begin();

        auto check = [&](int step) {
            for (int i = 1; i < n; i++) {
                int prev = (zero + (i - 1) * step + n) % n;
                int curr = (zero + i * step + n) % n;

                if (nums[prev] > nums[curr]) {
                    return false;
                }
            }

            return true;
        };

        int ans = INT_MAX;

        // 정방향(인덱스가 증가하는 방향)으로 원형 순서를 검사
        if (check(1)) {
            // 0이 있는 인덱스만큼 왼쪽으로 회전하면 오름차순 순열을 만들 수 있음
            ans = min(ans, zero);

            // 반대 방향의 회전과 뒤집기를 조합하는 경우의 연산 횟수
            // n - zero번의 회전과 뒤집기 2회가 필요
            ans = min(ans, n - zero + 2);
        }

        // 역방향(인덱스가 감소하는 방향)으로 원형 순서를 검사
        if (check(-1)) {
            // 뒤집기 2회와 zero번의 회전을 조합하는 경우
            ans = min(ans, zero + 2);

            // 반대 방향으로 회전하면 오름차순 순열을 만들 수 있음
            ans = min(ans, n - zero);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};