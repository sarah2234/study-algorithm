class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        vector<vector<int>> adj(strs.size());
        for (int i = 0; i < strs.size(); i++)
            for (int j = i + 1; j < strs.size(); j++)
            {
                if (isSimilar(strs[i], strs[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        
        vector<bool> visit(strs.size());
        int count = 0;
        for (int i = 0; i < strs.size(); i++)
        {
            if (!visit[i])
            {
                dfs(i, adj, visit);
                count++;
            }
        }
        
        return count;
    }
    
    bool isSimilar(string& a, string& b)
    {
        int diff = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
                diff++;
        }
        
        return diff == 0 || diff == 2;
    }
    
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visit)
    {
        visit[node] = true;
        for (int neighbor : adj[node])
        {
            if (!visit[neighbor]) 
            {
                dfs(neighbor, adj, visit);
            }
        }
    }
};