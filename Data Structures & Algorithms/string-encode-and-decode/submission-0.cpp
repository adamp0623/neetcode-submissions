class Solution {
public:

    string encode(vector<string>& strs) {
        // We are given a vector of strings. 
        // Need to assign a string value to each vector of strings.
        // Need some sort of key on each machine to be able to decode.

        // So ["Hello", "World"]
        // Encoding: "5#Hello5#World"
        if(strs.size() == 0) return "";

        string res;

        for(const string str:strs) {
            res += to_string(static_cast<int>(str.size()));
            res += '#';
            res += str;
        }
        return res;
    }

    vector<string> decode(string s) {

        if(s.size() == 0) return {};
        vector<string> res;

        // Looping through every character in the string.
        // Encoding: "5#Hello5#World"
        string size;
        for(int i = 0; i < static_cast<int>(s.size()); i++) {
            if(s[i] != '#') size += s.substr(i, 1);
            if(s[i] == '#') {
                int length = stoi(size);
                res.push_back(s.substr(i+1, length));
                i += length;
                size = "";
            }
            
    }
    return res;
    }
};