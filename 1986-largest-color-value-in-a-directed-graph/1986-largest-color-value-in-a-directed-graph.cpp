class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        queue<int> q;
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> inDegree(n, 0);
        vector<vector<int>> dp(n, vector<int>(26));

        for (auto& edge : edges)
        {
            graph[edge[0]].emplace_back(edge[1]);
            inDegree[edge[1]]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }

        int prev = 0;
        int cntNodes = 0;
        while (!q.empty()) 
        {
            int u = q.front(); q.pop();
            cntNodes++;

            int colorIndex = colors[u] - 'a';
            dp[u][colorIndex] += 1;

            for (int v : graph[u]) 
            {
                for (int c = 0; c < 26; ++c) 
                {
                    dp[v][c] = max(dp[v][c], dp[u][c]);
                }

                if (--inDegree[v] == 0)
                    q.push(v);
            }
        }

        if (cntNodes != n) 
            return -1;

        int ans = 0;
        for (auto& node : dp)
        {
            for (auto& color : node)
            {
                ans = max(ans, color);
            }
        }

        return ans;
    }
};