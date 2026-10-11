class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Each element of i, are the amount of days until a larger temperature appears.

        // Brute Force:
        // For each element, progress into the future until you find a warmer temperature
        // then record the number of days needed to do that. 

        // [30,38,30,36,35,40,28]

        // [40:5] 40:5  
        // [40:5, 28:5]   
        // [1, ] 
        vector<int> res(temperatures.size());

        vector<pair<int, int>> val_index;
        for(int i = 0; i < temperatures.size(); i++) {
            if(val_index.empty()) {
                val_index.push_back({temperatures[i], i});
                continue;
            }

            // If the new value is larger than the value at the top of the stack.
            while(temperatures[i] > val_index.back().first) {
                res[val_index.back().second] = (i - val_index.back().second);
                val_index.pop_back();
                if(val_index.empty()) break;
            }

            val_index.push_back({temperatures[i], i});

        }
        return res;
    }
};
