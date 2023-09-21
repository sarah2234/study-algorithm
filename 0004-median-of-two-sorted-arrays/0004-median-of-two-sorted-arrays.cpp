class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> combinedVec(nums1);
        combinedVec.insert(combinedVec.end(), nums2.begin(), nums2.end());
        std::sort(combinedVec.begin(), combinedVec.end());

        
        int size = combinedVec.size();
        if (size % 2 == 1)
            return (double)combinedVec[size / 2];
        else
            return (combinedVec[size / 2 - 1] + combinedVec[size / 2]) / (double)2;
    }
};