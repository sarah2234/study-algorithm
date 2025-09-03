class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq; //, vector<pair<double, int>>, less<pair<double, int>>

         auto delta = [](int p, int t) -> double {
            return (double)(p+1)/(t+1) - (double)p/t;
        };

        for (int i = 0; i < classes.size(); i++) {
            pq.push({delta(classes[i][0], classes[i][1]), i});
        }

        while (extraStudents-- > 0) {
            pair<double, int> top = pq.top(); pq.pop();
            int index = top.second;
            classes[index][0]++;
            classes[index][1]++;
            pq.push({delta(classes[index][0], classes[index][1]), index});
        }

        double ans = 0;
        for (const auto &c : classes) {
            ans += (double)c[0] / c[1];
        }

        return ans / classes.size();
    }
};