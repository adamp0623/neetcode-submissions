class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size()) return false;

        unordered_map<char,int> freq_s;
        unordered_map<char,int> freq_t;

        for(int i = 0; i < static_cast<int>(s.size()); i++) {
            freq_s[s[i]]++;
            freq_t[t[i]]++;
        }

        for(const auto&[key,value]:freq_s) {
            if(freq_t.find(key) == freq_t.end()) return false;
            else if(freq_t[key] != value) return false;
        }

        return true;
    }
};
