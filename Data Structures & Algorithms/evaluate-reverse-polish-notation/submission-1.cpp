class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // When you see an operator, perform that operation with the last two elements of the stack.
        // Save the result at the top of the stack. 
        vector<int> operands;
        for(const string s:tokens) {
            // Need to parse the string first. 
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                int num1 = operands.back();
                operands.pop_back();
                int num2 = operands.back();
                operands.pop_back();

                if(s == "+") operands.push_back(num1+num2);
                if(s == "-") operands.push_back(num2-num1);
                if(s == "*") operands.push_back(num1*num2);
                if(s == "/") operands.push_back(num2/num1);
            }
            else operands.push_back(stoi(s));
        }
        return operands.back();
    }
};
