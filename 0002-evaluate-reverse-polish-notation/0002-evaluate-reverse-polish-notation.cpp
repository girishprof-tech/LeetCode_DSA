class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (tokens[i] == "*" || tokens[i] == "/" || tokens[i] == "+" || tokens[i] == "-") {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();

                if (tokens[i] == "+") st.push(op1 + op2);
                else if (tokens[i] == "-") st.push(op1 - op2);
                else if (tokens[i] == "*") st.push(op1 * op2);
                else st.push(op1 / op2);
            }
            else {
                int temp = stoi(tokens[i]);
                st.push(temp);
            }
        }

        return st.top();
    }
};