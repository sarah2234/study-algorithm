class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int min = 1, max = 10000000;
        int speed = (min + max) / 2;
        int ans = -1;
        double total = 0;
        while (min <= max)
        {
            speed = (min + max) / 2;
            //cout << "speed: " << speed << " ";
            total = 0;
            for (int i = 0; i < n - 1; i++)
            {
                total += ceil(dist[i] / (double)speed);
            }
            total += (dist[n - 1] / (double)speed);
            //cout << "total: " << total << endl;
            if (total <= hour)
            {
                max = speed - 1;
                ans = speed;
            }
            else
                min = speed + 1;
        }
        
        return ans;
    }
};