class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int landTime = INT_MAX, waterTime = INT_MAX, minLandFirst = INT_MAX, minWaterFirst = INT_MAX;

        for (int i = 0; i < landStartTime.size(); i++) {
            landTime = min(landTime, landStartTime[i] + landDuration[i]);
        }

        for (int i = 0; i < waterStartTime.size(); i++) {
            waterTime = min(waterTime, waterStartTime[i] + waterDuration[i]);
            minLandFirst = min(minLandFirst, max(landTime, waterStartTime[i]) + waterDuration[i]);
        }

        for (int i = 0; i < landStartTime.size(); i++) {
            minWaterFirst = min(minWaterFirst, max(waterTime, landStartTime[i]) + landDuration[i]);
        }

        return min(minLandFirst, minWaterFirst);
    }
};