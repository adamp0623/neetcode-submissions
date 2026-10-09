class Solution {
public:
    string minWindow(string s, string t) {
        // Shortest substring, that contains all the characters in t, including duplicates
        // Firstly, we know order doesnt matter of how the characters in t exist in the substring

        // Approach:
        // Store the chars of t as keys and frequency as values.
        // Look at the valid window. 
        // "OUZODYXAZV"
        
        // Store a frequency map. We need to look for a window that has matching frequencies for 
        // the characters that exist in c.
        // Move the right pointer until that condition is satisfied. 
        // Once the condition is satisfied save the length,  start moving the left pointer in. 
        // If the condition is still satisfied, continue removing characters, once its not

        // "|OUZODYX|AZV"
        // "|XXY|XZ"

        unordered_map<char, int> t_freq;
        for(const char c: t) {
            t_freq[c]++;
        }

        unordered_map<char,int> window_freq;
        int shortest = s.size() + 1;
        int start_idx;
        int left = 0;
        // "|OUZODYXAZV"
        for(int right = 0; right < s.size(); right++) {

            // Need to add the value at right pointer to the frequency map.
            // Only add to the map if the key exists in the t_freq map, and window value 
            // is less than the t_freq value. 
            if(t_freq.find(s[right]) != t_freq.end()) window_freq[s[right]]++;

            // Need to check if value in the window map is greater than or equal to the t_freq map
            // at that key. If it is, go into the while loop.
            bool flag = 0;
            for(const auto&[key,value]: t_freq) {
                if(window_freq.find(key) == window_freq.end()) {
                    flag = 0;
                    break;
                }
                else if(value <= window_freq[key]) {
                    flag = 1;
                }
                else {
                    flag = 0;
                    break;
                }
            }
            // We need to move the left pointer in only after the window map contains the t map.
            while(flag) {
                // Update the shortest length, since its a valid string.
                if(right-left+1 < shortest) {
                    shortest = right - left + 1;
                    start_idx = left;
                }

                if(window_freq.find(s[left]) != window_freq.end()) {
                    window_freq[s[left]]--;
                    if(window_freq[s[left]] < 0) window_freq[s[left]] = 0;
                }

                left++;


                flag = 0;
                for(const auto&[key,value]: t_freq) {
                    if(window_freq.find(key) == window_freq.end()) {
                        flag = 0;
                        break;
                    }
                    else if(value <= window_freq[key]) {
                        flag = 1;
                    }
                    else {
                        flag = 0;
                        break;
                    }
                }

            }

        }
        if(shortest == s.size() + 1) return "";
        cout << shortest << endl;
        return s.substr(start_idx, shortest);
    }
};
