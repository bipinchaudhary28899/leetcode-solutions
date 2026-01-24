class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);  // Base index for valid substring
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);  // Reset base
                } else {
                    ans = max(ans, i - st.top());
                }
            }
        }

        return ans;
    }
};
