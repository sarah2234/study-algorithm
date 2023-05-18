class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> tri;
        tri.push_back(vector<int>(1, 1));
        if (numRows == 1)
            return tri;
        tri.push_back(vector<int>(2, 1));
        for (int i = 2; i < numRows; i++)
        {
            vector<int> tmp;
            tmp.push_back(1);
            for (int j = 0; j < tri[i - 1].size() - 1; j++)
            {
                tmp.push_back(tri[i - 1][j] + tri[i - 1][j + 1]);
            }
            tmp.push_back(1);
            tri.push_back(tmp);
        }
        
        return tri;
    }
};