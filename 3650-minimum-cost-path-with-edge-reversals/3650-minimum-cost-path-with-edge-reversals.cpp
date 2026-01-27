class Solution {
    using PAIR_INT = pair<int, int>;

public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<PAIR_INT>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2] * 2);
        }

        // cost 기준으로 min-heap 구성
        priority_queue<PAIR_INT, vector<PAIR_INT>, greater<PAIR_INT>> q;
        vector<int> minCost(n, INT_MAX);
        vector<bool> visited(n, false);
        
        minCost[0] = 0;
        q.emplace(0, 0);

        while (!q.empty()) {
            auto [cost, curr] = q.top();
            q.pop();

            if (curr == n - 1) {
                return minCost[curr];
            }

            if (visited[curr]) { 
                continue;
            }

            visited[curr] = true;

            for (auto& [next, weight] : adj[curr]) {
                if (minCost[curr] + weight < minCost[next]) {
                    minCost[next] = minCost[curr] + weight;
                    q.emplace(minCost[next], next);
                }
            }
        }

        return -1;
    }
};