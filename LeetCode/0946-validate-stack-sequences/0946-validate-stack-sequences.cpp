class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int index = 0;
        
        for (auto p : pushed)
        {
            stk.push(p);
            
            while (!stk.empty() && stk.top() == popped[index])
            {
                stk.pop();
                index++;
                if (index == popped.size())
                    return true;
            }
        }
        
        return index == popped.size();
    }
};
