class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // We need to identify all the substrings that have unique characters
        // Since a substring is contiguous, use a sliding window, with the condition
        // that we need keep valid, is that all the characters are unique.
        // We expand the window if the characters in the substring are unique.
        // We shrink the window if the new character added violates the coniditon
        // If we shrink the window, we store the maximum length we saw of a valid window.

        // Use a set of chars. Every iteration, we first check if it already exists in the set
        // if it does, shrink the window, removing the characters at the front of the window.

        // "yx|xzy|" {x,z, y}

        int longest = 0;
        int left = 0;
        unordered_set<char> chars;
        for(int right = 0; right < s.size(); right++) {
            
            // We need to shrink the window if its already in the set.
            while(chars.find(s[right]) != chars.end()) {
                chars.erase(s[left]);
                left++;
            }

            // This means the next up value is not in the set, add it.
            chars.insert(s[right]);

            // Everytime you add a unique value, add to the maximum length.
            longest = max(longest, static_cast<int>(chars.size()));
        }
        return longest;
    }
};
