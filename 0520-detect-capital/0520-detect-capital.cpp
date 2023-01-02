class Solution {
public:
    bool detectCapitalUse(string word) {
        // first letter is an uppercase
        if (isupper(word[0]))
        {
            // second letter is also an uppercase
            if (isupper(word[1]))
            {
                for (int i = 2; i < word.length(); i++)
                {
                    if (!isupper(word[i]))
                        return false;
                }
            }
            // second letter is a lowercase
            else
            {
                for (int i = 2; i < word.length(); i++)
                {
                    if (isupper(word[i]))
                        return false;
                }
            }
        }
        // first letter is a lowercase 
        else
        {
            for (int i = 1; i < word.length(); i++)
            {
                if (isupper(word[i]))
                    return false;
            }
        }
        
        return true;
        
    }
};