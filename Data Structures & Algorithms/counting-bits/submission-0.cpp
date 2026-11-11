class Solution {
public:
    vector<int> countBits(int n) {
        // This is essentially number of one bits from 0 to n.
        // You can do number of one bits for every number, but theres is def a more optimal approach
        vector<int> res;
        
        for(int i = 0; i <= n; i++) {
            int num_ones = 0;
            int n = i;
            while(n > 0) {
                if(n & 0b1) num_ones++;
                n = n >> 1;
            }
            res.push_back(num_ones);
        }
        return res;
    
    }
};
