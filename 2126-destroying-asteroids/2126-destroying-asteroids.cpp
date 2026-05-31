class Solution {
public:
    int BinarySearch(vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;
        
        while (left <= right) {
            int mid = (left + right) / 2;

            if (target == arr[mid]) return mid;
            else if (target < arr[mid]) right = mid - 1;
            else left = mid + 1;
        }

        return left - 1;
    }
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        int firstAsteroid = BinarySearch(asteroids, mass);
        double massDouble = mass;

        for (int i = 0; i <= firstAsteroid; i++) {
            massDouble += asteroids[i];
        }

        for (int i = firstAsteroid + 1; i < asteroids.size(); i++) {
            if (massDouble >= asteroids[i]) massDouble += asteroids[i];
            else return false;
        }

        return true;
    }
};