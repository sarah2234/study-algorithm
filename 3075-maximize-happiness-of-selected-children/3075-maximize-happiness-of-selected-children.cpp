class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        int turn = 0;

        sort(happiness.begin(), happiness.end(), greater<>());

        for (int i = 0; turn++ < k && i < happiness.size(); i++) {
            if (happiness[i] - i <= 0) {
                break;
            }    

            ans += happiness[i] - i;
        }
        
        return ans;
    }
};