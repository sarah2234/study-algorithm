class Solution {
public:
    int countCollisions(string directions) {
        stack<char> st;  
        int ans = 0;

        for (char c : directions) {

            if (c == 'R') {
                st.push('R');
            } 
            else if (c == 'S') {
                while (!st.empty() && st.top() == 'R') {
                    ans += 1;   
                    st.pop();
                }
                st.push('S');
            }
            else { 
                if (st.empty()) continue; 

                if (st.top() == 'R') {
                    ans += 2;
                    st.pop();

                    while (!st.empty() && st.top() == 'R') {
                        ans += 1;
                        st.pop();
                    }

                    st.push('S');
                } 
                else if (st.top() == 'S') {
                    ans += 1;
                }
            }
        }

        return ans;
    }
};
