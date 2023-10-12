/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int left = 0, right = mountainArr.length();
        int mid;
        int lValue, mValue, rValue;

        do {
            mid = (left + right) / 2;
            lValue = mountainArr.get(mid - 1);
            rValue = mountainArr.get(mid + 1);
            mValue = mountainArr.get(mid);
            if (lValue > mValue && mValue > rValue)
                right = mid;
            else if (lValue < mValue && mValue < rValue)
                left = mid;
        } while (!(lValue < mValue && rValue < mValue));

        int peek = mid;

        // search left first
        left = 0;
        right = peek - 1;
        do {
            mid = (left + right) / 2;
            mValue = mountainArr.get(mid);

            if (mValue < target)
                left = mid + 1;
            else if (mValue > target) 
                right = mid - 1;
            else
                return mid;
        } while (left <= right);

        // search right last
        left = peek;
        right = mountainArr.length() - 1;
        do {
            mid = (left + right) / 2;
            mValue = mountainArr.get(mid);

            if (mValue > target) 
                left = mid + 1;
            else if (mValue < target)
                right = mid - 1;
            else
                return mid;
        } while (left <= right);

        return -1;
    } 
};