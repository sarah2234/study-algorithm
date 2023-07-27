class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int prev = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (prev > arr[i])
                return i - 1;
            prev = arr[i];
        }
        return n - 1;
    }
};