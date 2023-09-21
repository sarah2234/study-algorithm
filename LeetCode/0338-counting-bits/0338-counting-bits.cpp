class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0)
            return vector(1, 0);
        
        vector<int> ans;
        
        /*for (int i = 0; i < n + 1; i++) {
            ans[i] = bitset<20>(i).count();
        }*/
        
        ans.push_back(0);
        ans.push_back(1);
        
        int step = 2;
        int ref = 0;
        int i = 0;
        while (ans.size() < n + 1) {
            if (i < ref) {
                ans.push_back(ans[ref + i++]);
            } else if (i < step) {
                ans.push_back(ans[ref + i++] + 1);
            } else if (i == step) {
                i = 0;
                ref = step;
                step *= 2;
            }
        }
        
        return ans;
    }
};