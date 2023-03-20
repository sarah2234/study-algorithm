class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        bool check[3] = {false, false, false};
        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (i != 0)
            { 
                if (flowerbed[i - 1] == 1)
                    check[0] = true;
                else
                    check[0] = false;
            }
            if (flowerbed[i] == 1)
                check[1] = true;
            else
                check[1] = false;
            if (i != flowerbed.size() - 1)
            {
                if (flowerbed[i + 1] == 1)
                    check[2] = true;
                else
                    check[2] = false;
            }
            
            if (check[0] == false && check[1] == false && check[2] == false)
            {
                flowerbed[i] = 1;
                n--;
            }
        }
        
        if (n <= 0)
            return true;
        else 
            return false;
    }
};