class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        
        vector<vector<int>> group(501, vector<int>(0, 0));
        for (int i = 0; i < groupSizes.size(); i++) {
            group[groupSizes[i]].push_back(i);
        }
        
        for (int i = 1; i <= 500; i++) {
            vector<int> tmp;
            for (int j = 0; j < group[i].size(); j++) {
                tmp.push_back(group[i][j]);
                
                if (tmp.size() == i) {
                    ans.push_back(tmp);
                    tmp.clear();
                }
            }
        }
        
        return ans;
    }
};