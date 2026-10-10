class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 1) return false;

        vector<char> brackets;
        for(const char c:s) {
            if(c == '(' || c == '{' || c == '[') brackets.push_back(c);
            else if(brackets.empty()) return false;
            else if(c == ')' && brackets.back() != '(') return false;
            else if(c == '}' && brackets.back() != '{') return false;
            else if(c == ']' && brackets.back() != '[') return false;
            else{
                brackets.pop_back();
            }
        }
        if(!brackets.empty()) return false;
        return true;
    }
};
