class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        pair<int, int> maxDiagonal; // index, diagonal

        for (int i = 0; i < dimensions.size(); i++) {
            unsigned int diagonal = dimensions[i][0] * dimensions[i][0] 
            + dimensions[i][1] * dimensions[i][1];
            bool changeMaxIndex = false;

            if (maxDiagonal.second < diagonal) {
                changeMaxIndex = true;
            } 
            else if (maxDiagonal.second == diagonal) {
                int maxSize = dimensions[maxDiagonal.first][0] * dimensions[maxDiagonal.first][1];
                int size = dimensions[i][0] * dimensions[i][1];

                if (maxSize < size) {
                    changeMaxIndex = true;
                } 
            }

            if (changeMaxIndex) {
                maxDiagonal.first = i;
                maxDiagonal.second = diagonal;
            }
        }

        return dimensions[maxDiagonal.first][0] * dimensions[maxDiagonal.first][1];
    }
};