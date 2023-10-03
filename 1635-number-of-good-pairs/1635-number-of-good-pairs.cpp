class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int map[101] = {};
        int ans = 0;
        
        for (int num: nums) {
            ans += map[num]++;
        }
        
        return ans;
    }
};