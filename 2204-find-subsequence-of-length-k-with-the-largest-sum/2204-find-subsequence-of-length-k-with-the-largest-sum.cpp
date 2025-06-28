class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

        // (값, 인덱스) 저장
        vector<pair<int, int>> valueWithIndex;
        for (int i = 0; i < n; ++i)
            valueWithIndex.emplace_back(nums[i], i);

        // 값 기준 내림차순 정렬
        sort(valueWithIndex.begin(), valueWithIndex.end(),
             [](auto& a, auto& b) {
                 return a.first > b.first;
             });

        // 상위 k개만 추출
        vector<int> selectedIndices;
        for (int i = 0; i < k; ++i)
            selectedIndices.push_back(valueWithIndex[i].second);

        // 인덱스를 오름차순으로 정렬 → subsequence 유지
        sort(selectedIndices.begin(), selectedIndices.end());

        // subsequence 생성
        vector<int> result;
        for (int index : selectedIndices)
            result.push_back(nums[index]);

        return result;
    }
};
