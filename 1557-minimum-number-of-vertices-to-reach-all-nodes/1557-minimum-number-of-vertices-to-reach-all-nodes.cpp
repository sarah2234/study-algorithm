class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<bool> check(n, 0);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                check[adj[i][j]] = true;
            }
        }
         
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (check[i] == false)
                ans.push_back(i);
        }
        
        return ans;
    }
};