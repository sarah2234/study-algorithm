class Solution {
public:
    int CalcEndTime(vector<int>& firstStartTime, vector<int>& firstDuration, vector<int>& secondStartTime, vector<int>& secondDuration) {
        int finalEndTime = INT_MAX, firstEndTime = INT_MAX;

        for (int i = 0; i < firstStartTime.size(); i++) {
            int check = firstStartTime[i] + firstDuration[i];

            if (check < firstEndTime) firstEndTime = check;
        }

        for (int i = 0; i < secondStartTime.size(); i++) {
            int check = (firstEndTime >= secondStartTime[i]) ? firstEndTime + secondDuration[i] : secondStartTime[i] + secondDuration[i];

            if (check < finalEndTime) finalEndTime = check;
        }

        return finalEndTime;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int landFirst = CalcEndTime(landStartTime, landDuration, waterStartTime, waterDuration);
        int waterFirst = CalcEndTime(waterStartTime, waterDuration, landStartTime, landDuration);

        return min(landFirst, waterFirst);
    }
};