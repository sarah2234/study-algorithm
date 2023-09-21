bool cmp(vector<int>& v1, vector<int>& v2)
{
    if (v1[1] == v2[1])
        return v1[0] < v2[0];
    else return v1[1] < v2[1];
}

class Solution {
public: 
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        int cmpFirst = intervals[0][0], cmpSecond = intervals[0][1];
        int cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (cmpFirst != intervals[i][0] && cmpSecond <= intervals[i][0])
            {
                cnt++;
                cmpFirst = intervals[i][0];
                cmpSecond = intervals[i][1];
            }
        }
        return n - cnt;
    }
};