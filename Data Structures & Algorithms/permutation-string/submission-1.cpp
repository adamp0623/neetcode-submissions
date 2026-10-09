class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // True: if s2 contains a permutation of s1
        // False: otherwise.

        // Approach: Fixed Sliding Window
        // First save the length of s1, this is the size of the fixed window
        // Create a map, storing letters and frequencies.

        // Slide a window of fixed size on s2, add all the elements of the fixed
        // window to a hash map. Check if both maps contain the same letters, and letter    
        // frequencies.

        // s1 = "abc" s2 = "lecabee"
        // s1.size() = 3, {a:1, b:1, c:1}
        // "|leca|bee"
        // Return true, if we find a window, that has the same keys and values as map of s1

        unordered_map<char,int> s1_freq;
        for(const char c:s1) {
            s1_freq[c]++;
        }

        int left = 0;
        bool flag = 0;

        // s1 = "abc" s2 = "lecabee"
        // s1.size() = 3, {a:1, b:1, c:1}
        // "le|cab|ee" {l:1,e:1,c:1}

        // s2="ooolleoooleh"
        unordered_map<char,int> window_freq;
        for(int right = 0; right < s2.size(); right++) {

            window_freq[s2[right]]++;

            if(right - left + 1 == s1.size()) {
                for(const auto&[key,value]:window_freq) {
                    if(s1_freq.find(key) == s1_freq.end() || value != s1_freq[key]) {
                        // If there is a key, or value mismatch, need to continue looking.
                        window_freq[s2[left]]--;
                        if(window_freq[s2[left]] == 0) window_freq.erase(s2[left]);
                        left++;
                        flag = 0;
                        break;
                    }
                    else {
                        flag = 1;
                    }
                }
                if(flag == 1) return true;
            }
        }
        return false;
    }
};
