class Solution {
public:
    double average(vector<int>& salary) {
        unsigned int min = min_element(salary.begin(), salary.end()) - salary.begin();
        unsigned int max = max_element(salary.begin(), salary.end()) - salary.begin();
        double answer = 0;
        for (int i = 0; i < salary.size(); i++)
        {
            if (i != min && i != max)
            {
                answer += salary[i];
                //cout << answer << endl;
            }
        }
        answer /= (salary.size() - 2);
        return answer;
    }
};