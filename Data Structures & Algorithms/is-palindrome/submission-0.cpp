class Solution {
public:
    bool isPalindrome(string s) {
        // Need to remove all non-alphanumeric characters
        string copy;
        for(const char c:s) {
            if(c <= 'Z' && c >= 'A') {
                int pos = c - 'A';
                copy += ('a' + pos);
            }
            if(c <= 'z' && c >= 'a') {
                copy += c;
            }
            if(c <= '9' && c >= '0') {
                copy += c;
            }

        }
        
        // "racecar"
        // start from each end, into the middle. If any values are different, return false.
        int left = 0;
        int right = copy.size()-1;
        while(left < right) {
            if(copy[left] != copy[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
