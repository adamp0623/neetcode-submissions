class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // First sort them by starting value.
        // 1 - 3
        // 1 - - - 5
        // For each interval, check if the next interval 
        // starts between the first interval range.
        // If not, they dont overlap, add it to res and move next.
        // If they do overlap, check which interval between
        // the two have a later end. 
        // Push to res the starting of the first,
        if(intervals.size() == 1) return intervals;
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        for (const auto& interval : intervals) {
            if (res.empty() || interval[0] > res.back()[1]) {
                res.push_back(interval);
            }
            else {
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }

        return res;
    }
};
