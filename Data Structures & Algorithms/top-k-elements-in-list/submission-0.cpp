class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Top K frequent elements.
        // Need to store frequenc

        unordered_map<int,int> freq;

    
        for(const int num: nums) {
            freq[num]++;
        }

        // Frequency can be at most length(nums)
        // Maybe we can start at length(nums), and keep checking the hash map to see 
        // if there is a frequency that matches that. Thats brute force. Try it

        // Better approach, bucket sort. Put value in buckets indexed by frequency.
        // Index i corresponds to frequency i + 1
        //            F=1    F=2    F=3
        // Contains [[1, 2] [3, 4] [5,6]]
        vector<vector<int>> buckets(nums.size()); // [[], [], [], ...]
        for(const auto&[key, value]: freq) {
            // ith bucket contains numbers that have a i + 1 frequency.
            buckets[value - 1].push_back(key);
        }

        vector<int> res;
        for(int i = buckets.size() - 1; i >= 0; i--) {
            if(buckets[i].size() == 0) continue;
            
            for(const int num:buckets[i]) {
                res.push_back(num);
                k--;
            }

            if(k == 0) break;
        }
        return res;

        // vector<int> res;
        // for(int i = nums.size(); i > 0; i--) {
        //     for(const auto&[key, value]: freq) {
        //         if(value == i) {
        //             res.push_back(key);
        //             k--;
        //         }
        //     }
        //     if(k == 0) break;
        // }
        // return res;
    }
};
