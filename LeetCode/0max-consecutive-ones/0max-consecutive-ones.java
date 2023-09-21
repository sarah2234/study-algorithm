class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int length = 0;
        int tmp = 0;
        
        for (int num : nums) {
            if (num == 0) {
                length = Math.max(length, tmp);
                tmp = 0;
            } else {
                tmp++;
            }
        }
        length = Math.max(length, tmp);
        
        return length;
    }
}