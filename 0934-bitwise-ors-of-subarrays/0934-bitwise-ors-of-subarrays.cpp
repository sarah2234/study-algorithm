class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        unordered_set<int> prev;

        for (auto n : arr) {
            unordered_set<int> curr;
            curr.insert(n);

            for (auto p : prev) {
                curr.insert(p | n);
            }

            ans.insert(curr.begin(), curr.end());
            prev = curr;
        }

        return ans.size();
    }
};