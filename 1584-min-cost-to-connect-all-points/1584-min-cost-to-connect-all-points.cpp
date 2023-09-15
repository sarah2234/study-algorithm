class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<int> parent;
        vector<pair<int, pair<int, int>>> edges;
        int n = points.size();

        for (int i = 0; i < n; ++i) {
            parent.push_back(i);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({cost, {i, j}}); // 모든 간선 구하기
            }
        }

        sort(edges.begin(), edges.end());

        int min_cost = 0, num_edges = 0;

        for (auto& edge : edges) {
            int cost = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            if (find(parent, u) != find(parent, v)) { // u와 v가 서로 다른 집합에 속해 있을 때 -> cycle 형성 방지
                unionSets(parent, u, v); // u, v를 같은 집합에 둠 (집합: parent)
                min_cost += cost;
                num_edges++;
            }

            if (num_edges == n - 1) {
                break; // 선분 다 그림
            }
        }

        return min_cost;
    }

private:
    int find(vector<int>& parent, int x) {
        if (parent[x] == x) {
            return x;
        }
        parent[x] = find(parent, parent[x]);
        return parent[x];
    }

    void unionSets(vector<int>& parent, int x, int y) {
        parent[find(parent, x)] = find(parent, y);
    }
};
