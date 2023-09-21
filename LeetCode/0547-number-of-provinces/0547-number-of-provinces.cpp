class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> check(n, false);
        queue<int> q;
        int ans = 0;
        
        for (int city = 0; city < n; city++)
        {
            if (!check[city])
            {
                q.push(city);
                ans++;
            }
            while(!q.empty())
            {
                int i = q.front();
                check[i] = true;
                q.pop();
                for (int k = 0; k < n; k++)
                {
                    if (isConnected[i][k] && !check[k])
                    {
                        q.push(k);
                    }
                }
            }
        }
        return ans;
    }
};