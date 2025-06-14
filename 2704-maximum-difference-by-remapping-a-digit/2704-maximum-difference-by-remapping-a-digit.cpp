class Solution {
public:
    int minMaxDifference(int num) {
        vector<int> remappedNums(10);
        int maxNum = 1, minNum = 100000000;

        for (int i = 0; i < 10; i++)
        {
            string strNum = std::to_string(num);
            string changeToNines = "", changeToZeros = "";

            for (auto c : strNum)
            {
                if (c - '0' == i)
                {
                    changeToNines += '9';
                    changeToZeros += '0';
                }
                else
                {
                    changeToNines += c;
                    changeToZeros += c;
                }
            }

            maxNum = max(maxNum, stoi(changeToNines));
            minNum = min(minNum, stoi(changeToZeros));
        }

        return maxNum - minNum;
    }
};