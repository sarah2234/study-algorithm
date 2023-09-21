class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        unsigned long long length = 0;
        unsigned long long cnt = 0;
        for (auto num : nums)
        {
            if (num == 0)
            {
                length++;               
            }
            else if (length != 0)
            {
                cnt = cnt + (length + 1) * length / 2;
                length = 0;
                //cout << "none" << endl;
            }
            
            //cout << "cnt: " <<cnt<< " length: " << length << endl;
        }
        
        if (length != 0)
            cnt = cnt + (length + 1) * length / 2;
        return cnt;
    }
};