class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }
        
        vector<bool> flag(n);
        vector<vector<int>> adj(n);
        int node = 0;
        int cnt = 0;
        
        for (int i = 0; i < connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        int numberOfConnectedComponents = 0;

        for (int i = 0; i < n; i++) {
            if (!flag[i]) {
                cout << i << endl;
                numberOfConnectedComponents++;
                dfs(i, adj, flag);
            }
        }

        return numberOfConnectedComponents - 1;
    }
    
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& flag)
    {      
        flag[node] = true;
        for (auto edge : adj[node])
        {
            if (flag[edge] == false)
            {
                //cout<<"visit "<<edge<<endl;
                dfs(edge, adj, flag);
            }
        }
    }
};