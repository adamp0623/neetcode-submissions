class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // We need to reverse the bits here. 
        // Reversing means least significant bits become the most significant bits.
        // Starting from the LSB, OR it with the res, and then shift the res left. 
        // 000000000000000000000000000000000
        // 11111111111111111111111111111101
        uint32_t res = 0;
        for(int i = 0; i < 32; i++) {
            res <<= 1;
            if(n & 0b1) {
                //cout << "flipped" << endl;
                res |= 0b1;
            }
            //cout << res << endl;
            n >>= 1;
        }
        return res;
    }
};
