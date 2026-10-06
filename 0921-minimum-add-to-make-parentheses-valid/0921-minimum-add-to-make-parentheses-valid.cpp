class Solution {
public:
    int minAddToMakeValid(string s) {
        int cntOpenBrackets = 0;
        int answer = 0;

        for (char c : s) {
            if (c == '(') {
                cntOpenBrackets++;
            } 
            else {
                if (cntOpenBrackets > 0) {
                    cntOpenBrackets--;
                }
                else {
                    answer++;
                }
            }
        }

        return answer + cntOpenBrackets;
    }
};