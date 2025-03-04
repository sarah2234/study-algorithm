class Solution {
public:
    bool checkPowersOfThree(int n) {
        int index = 0;

        while (pow(3, index + 1) <= n)
        {
            index++;
        }

        for (int i = index; i >= 0; i--)
        {
            int result = n - (int)pow(3, i);
            
            if (result > 0)
            {
                n = result;
            }
            else if (result == 0)
            {
                return true;
            }
        }

        return false;
    }
};