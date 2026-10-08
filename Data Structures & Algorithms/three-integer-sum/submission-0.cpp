class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Triplets need to add up to zero
        // Should not contain duplicate triplets
        // Breaking this problem down
        // Do a two sum problem for each element in the array, where the target would be the 
        // negative of the current value in the index

        // [-1,0,1,2,-1,-4]
        // Starting at value -1, need to search the rest of the array for two values that add up
        // to -(-1) = 1. If it cant be found, dont add a triplet to the resultant list.

        // [-2, 1, 1]
        // Target: 2 partner: 2 - 1 = 1 seen{1: 1} partner: 2 - 1 = 1 

        // Accidentally reporting duplicates.
        set<vector<int>> triplets;
        for(int i = 0; i < nums.size(); i++) {

            int target = -nums[i];

            unordered_map<int, int> seen;
            for(int j = 0; j < nums.size(); j++) {
                if(j == i) continue;
                int partner = target - nums[j];
                if(seen.find(partner) != seen.end()) {
                    vector<int> triplet = {nums[i], nums[seen[partner]], nums[j]};
                    sort(triplet.begin(), triplet.end());

                    triplets.insert(triplet);
                }
                seen[nums[j]] = j;
            }
        }
        
        vector<vector<int>> res;
        for(const auto vec: triplets) {
            res.push_back(vec);
        }
        return res;
    }
};
