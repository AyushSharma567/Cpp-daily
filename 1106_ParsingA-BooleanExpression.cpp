//question: https://leetcode.com/problems/parsing-a-boolean-expression/

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char c : expression) {
            if (c == ',' || c == '(') 
                continue;
            else if (c == 't' || c == 'f' || c == '!' || c == '&' ||
                       c == '|') 
                st.push(c);
            else if (c == ')') {
                bool hasTrue = false, hasFalse = false;
                char op = ' '; 
                while (st.top() != '!' && st.top() != '&' && st.top() != '|') {
                    char top = st.top();
                    st.pop();
                    if (top == 't')
                        hasTrue = true;
                    if (top == 'f')
                        hasFalse = true;
                }

                op = st.top();
                st.pop();
                bool result;
                if (op == '!') 
                    result = !hasTrue; 
                else if (op == '&') 
                    result = !hasFalse; 
                else if (op == '|') 
                    result = hasTrue; 

                st.push(result ? 't' : 'f');
            }
        }

        return st.top() == 't';
    }
};