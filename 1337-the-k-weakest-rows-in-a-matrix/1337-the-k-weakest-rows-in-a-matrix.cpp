class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> numOfSoldiers;
        vector<int> weakestRow;
        
        for (int i = 0; i < m; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    cnt++;
                } else {
                    break;
                }
            }
            numOfSoldiers.push_back(make_pair(cnt, i));
        }
        
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        };
        sort(numOfSoldiers.begin(), numOfSoldiers.end(), cmp);
        
        for (int i = 0; i < k; i++) {
            weakestRow.push_back(numOfSoldiers[i].second);
        }    
        
        return weakestRow;
    }
};