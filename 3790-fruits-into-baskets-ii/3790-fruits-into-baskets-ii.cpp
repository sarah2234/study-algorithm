class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int avail = 0;
        vector<bool> used(baskets.size());

        for (int i = 0; i < fruits.size(); i++) {
            for (int j = 0; j < baskets.size(); j++) {
                if (fruits[i] <= baskets[j] && !used[j]) {
                    avail++;
                    used[j] = true;
                    break;
                }
            }
        }

        return fruits.size() - avail;
    }
};