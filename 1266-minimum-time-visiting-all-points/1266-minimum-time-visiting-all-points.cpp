class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        
        for (int i = 0; i < points.size() - 1; i++) {
            vector<int> curr = points[i];
            vector<int> next = points[i + 1];

            int diffX = next[0] - curr[0];
            int diffY = next[1] - curr[1];

            ans += max(abs(diffX), abs(diffY));
        }

        return ans;
    }
};