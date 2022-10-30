class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string word1_append = "", word2_append = "";
        for(int i = 0; i < word1.size(); i++)
        {
            word1_append += word1[i];
        }
        for(int i = 0; i < word2.size(); i++)
        {
            word2_append += word2[i];
        }
        
        if(word1_append == word2_append)
            return true;
        
        return false;
    }
};