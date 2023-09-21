class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char first = letters[0];
        sort(letters.begin(), letters.end());
        int low = 0;
        int high = letters.size() - 1;
        int mid;
        
        while (low <= high) 
        {
            mid = (high + low) / 2;

            if (letters[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low == letters.size() ? first : letters[low];
    }
};