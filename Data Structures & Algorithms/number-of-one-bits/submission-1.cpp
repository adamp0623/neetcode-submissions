class Solution {
public:
    int hammingWeight(uint32_t n) {
        // Need to count the number of bits.
        int num_ones = 0;
        while(n > 0) {
            if(n & 0b1) num_ones++;
            n = n >> 1;
        }
        return num_ones;

    }
};
