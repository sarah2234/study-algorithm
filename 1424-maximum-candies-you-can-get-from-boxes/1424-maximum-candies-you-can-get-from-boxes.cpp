class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, 
                   vector<vector<int>>& keys, 
                   vector<vector<int>>& containedBoxes, 
                   vector<int>& initialBoxes) {
        
        int totalCandies = 0;
        queue<int> q;
        unordered_set<int> boxes(initialBoxes.begin(), initialBoxes.end());
        vector<bool> visited(status.size(), false);

        // 초기 열린 박스 큐에 넣기
        for (int box : initialBoxes) {
            if (status[box]) {
                q.push(box);
                visited[box] = true;
            }
        }

        while (!q.empty()) {
            int curr = q.front(); q.pop();
            totalCandies += candies[curr];

            // 새로운 키로 박스를 열 수 있게 함
            for (int key : keys[curr]) {
                if (!status[key]) {
                    status[key] = 1;
                    if (boxes.count(key) && !visited[key]) {
                        q.push(key);
                        visited[key] = true;
                    }
                }
            }

            // 새로운 박스 발견
            for (int box : containedBoxes[curr]) {
                boxes.insert(box);
                if (status[box] && !visited[box]) {
                    q.push(box);
                    visited[box] = true;
                }
            }
        }

        return totalCandies;
    }
};
