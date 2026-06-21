class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        unsigned long long currCost = 0;

        for (int i = 0; i < costs.size(); i++) {
            currCost += costs[i];

            if (currCost > coins) {
                return i;
            }
        }

        return costs.size();
    }
};