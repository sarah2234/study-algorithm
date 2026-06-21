class Solution {
public:
    int maxBuilding(int num, vector<vector<int>>& r) {
        r.push_back({1, 0});
        sort(r.begin(), r.end());
        int n = r.size();

        for (int i = 1; i < n; i++)
            r[i][1] = calcRestriction(r[i - 1], r[i]);

        for (int i = n - 2; i >= 0; i--)
            r[i][1] = calcRestriction(r[i + 1], r[i]);

        int res = 0;
        for (int i = 1; i < n; i++)
            // restriction 사이간 최고점 계산
            res = max(res, calcHighestPeak(r[i - 1], r[i]));

        // res와 마지막 resctriction 이후 계속해서 높이가 증가했을 때 비교
        return max(res, r[n - 1][1] + (num - r[n - 1][0]));
    }

    int calcRestriction(vector<int>& prevRestriction, vector<int>& currRestriction) {
        int x1 = prevRestriction[0], y1 = prevRestriction[1], x2 = currRestriction[0], y2 = currRestriction[1];
        return min(y2, y1 + abs(x2 - x1));
    }

    int calcHighestPeak(vector<int>& left, vector<int>& right) {
        int x1 = left[0], y1 = left[1], x2 = right[0], y2 = right[1];
        // 최고 높이가 H, x2 - x1 = d일 때
        // 왼쪽에서 꼭대기까지 올라가는 데 필요한 거리 : H - y1
        // 오른쪽에서 꼭대기까지 올라가는 데 필요한 거리 : H - y2
        // (H - y1) + (H - y2) = d
        // H = (d + y1 + y2) / 2 = (x2 - x1 + y1 + y2) / 2
        return (y1 + y2 + x2 - x1) >> 1;
    }
};