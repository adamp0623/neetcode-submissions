class Solution {
public:
    int getSum(int a, int b) {
        // How are negative integers represented? Twos complement? 
        // 10101
        //+10101
        // The resulting bit: if both are 1, return 0, carry a bit to the next
        // operation. 
        // You have a carry bit, bit1, bit2.

        uint32_t x = static_cast<uint32_t>(a);
        uint32_t y = static_cast<uint32_t>(b);
        uint32_t res = 0;
        bool carry = false;

        for (int n = 0; n < 32; n++) {
            // Keep your existing per-bit logic,
            // replacing a with x and b with y.
            if((x & 0b1) && (y & 0b1)){
                if(carry) res |= (1U << n);
                carry = true;
            }
            else if((x & 0b1) || (y & 0b1)) {
                if(!carry) res |= (1U << n);
            }
            else if(carry) {
                res |= (1U << n);
                carry = false;
            }

            x >>= 1;
            y >>= 1;
        }
        
        return res;


    }
};
