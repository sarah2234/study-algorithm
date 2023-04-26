class Solution {
public:
    int addDigits(int num) {
        while (num / 10 > 0)
        {
            vector<int> n;
            for (int i = 9; i >= 0; i--)
            {
                n.push_back(num / pow(10, i));
                num = (int)(num % (int)pow(10, i));
                //cout << "num: " << num << endl;
            }
            
            num = 0;
            for (auto i : n)
            {
                num += i;
            }
        }
        
        return num;
    }
};