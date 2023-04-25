class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1)
        {
            sort(stones.begin(), stones.end(), greater<int>());
            int first = stones[0];
            int second = stones[1];
            cout << "first: " << first <<" second: " << second << ", size: " << stones.size() << endl;
            stones.erase(stones.begin());
            stones.erase(stones.begin());
            if (first - second != 0)
            {
                stones.push_back(first - second);
            }
        }
        
        if (stones.size() != 0)
            return stones[0];
        return 0;
    }
};