class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, 
                   vector<vector<int>>& keys, 
                   vector<vector<int>>& containedBoxes, 
                   vector<int>& initialBoxes) {
        
        int totalCandies = 0;
        queue<int> q;
        unordered_set<int> boxes;
        unordered_set<int> seen;

        for (int box : initialBoxes) {
            boxes.insert(box);
            if (status[box]) q.push(box);
        }

        while (!q.empty()) {
            int box = q.front(); q.pop();
            if (seen.count(box)) continue;
            seen.insert(box);

            totalCandies += candies[box];

            // 얻은 키로 박스를 열 수 있게 만들기
            for (int key : keys[box]) {
                status[key] = 1;
                if (boxes.count(key) && !seen.count(key)) {
                    q.push(key);
                }
            }

            // 얻은 박스를 기억해두기
            for (int newBox : containedBoxes[box]) {
                boxes.insert(newBox);
                if (status[newBox] && !seen.count(newBox)) {
                    q.push(newBox);
                }
            }
        }

        return totalCandies;
    }
};
