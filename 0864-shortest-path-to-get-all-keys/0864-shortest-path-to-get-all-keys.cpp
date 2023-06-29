class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        unordered_map<char, int> key_bit;
        int bit_start = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (islower(grid[i][j]))
                    key_bit[grid[i][j]] = bit_start++;
            }
        }
        
        int form_end = (1 << bit_start) - 1;
        int form_size = (1 << bit_start);
        
        vector<vector<vector<bool>>> memo(m, vector<vector<bool>> (n, vector<bool> (form_size, false)));
        
        vector<int> start;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '@')
                    start = {i, j, 0}; // 0 denoting no key state
            }
        }
        
        queue<vector<int>> q;
        q.push(start);
        int steps  = 0; // step counter
        
        while (!q.empty())
        {
            int size = q.size();
            for (int k = 0; k < size; k++)
            {
                int row = q.front()[0];
                int col = q.front()[1]; // current location
                int form = q.front()[2]; // current key possession state
                q.pop();
                
                // check if out of bounds
                if (row < 0 || row >= m || col < 0 || col >= n)
                    continue;
                
                // check if position is blocked
                if (grid[row][col] == '#')
                    continue;
                
                // check if the key is required but not collected
                if (isupper(grid[row][col]))
                {
                    if ((form & (1 << key_bit[tolower(grid[row][col])])) == 0)
                        continue;
                }
                
                // if the position contains a key, collect it
                if (islower(grid[row][col]))
                    form = form | (1 << key_bit[grid[row][col]]);
                
                // if all keys are collected, return the step count
                if (form == form_end)
                    return steps;
                
                // if the position and form combination has been visited, continue to the next iteration
                if (memo[row][col][form])
                    continue;
                memo[row][col][form] = true;
                
                // add adjacent positions to the queue
                q.push({row + 1, col, form});
                q.push({row, col + 1, form});
                q.push({row - 1, col, form});
                q.push({row, col - 1, form});
            }
            steps++; // increment step count
        }
        
        return -1;
    }
};