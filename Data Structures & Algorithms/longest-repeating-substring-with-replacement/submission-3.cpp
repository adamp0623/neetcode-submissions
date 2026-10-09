class Solution {
public:
    int characterReplacement(string s, int k) {
        // Given string s, int k, 
        // Replace up to k integers, replace them with any other letter
        // After at most k replacements, return length of longest substring containing
        // one distinct letter.

        // A valid window: window_length = char_highest_frequency - k
        // Invalid Window: char_highest_freq - window length > k
        unordered_map<char, int> freq;
        int max_freq = 0;
        int left = 0;
        int max_length = 0;

        // A valid window contains at most k replacements. 
        // # of replacements = window length - char with highest freq in the window 
        // Everytime a left value is removed, remove the element from the map, update the max.
        for(int right = 0; right < s.size(); right++) {

            freq[s[right]]++;
            max_freq = max(max_freq, freq[s[right]]);

            while((right - left + 1) - max_freq > k) {
                freq[s[left]]--;
                left++;
            }
            max_length = max(max_length, right - left + 1);
        }
        return max_length;
        
    }
};
