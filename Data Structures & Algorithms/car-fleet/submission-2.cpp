class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // time = distance / speed
        // For each car, calculate the time they would arrive at the destination
        // if they were unimpeded by traffic
        // time = (target - position[i]) / speed[i]
        // If the arrival times are monotonically decreasing, then there are 
        // as many fleets as cars. 
        // [1,4,2,1]
        // [1,4,2,1] 
        // There is a fleet formed when for the ith element, the i+1 element
        // is arriving later than it. 
        // [1] 4, arriving later. Pop [1] and add [4]
        // [4,2,1], this is all decreasing, so these are individual fleets.
        // Return size of this stack.

        vector<pair<int,int>> pos_speed(position.size());
        for(int i = 0; i < position.size(); i++) {
            pos_speed[i] = {position[i], speed[i]};
        }

        sort(pos_speed.rbegin(), pos_speed.rend());

        vector<double> arrival_times(position.size());
        for(int i = 0; i < position.size(); i++) {
            arrival_times[i] = static_cast<double>(target - pos_speed[i].first) / pos_speed[i].second;
        } 

        vector<double> groups;
        // [7,4,1,0]
        // [3, 2, 4, 10]
        // [3,4,10]    
           
        int res = 0;
        for(int i = 0; i < position.size(); i++) {
            if(groups.empty()) {
                groups.push_back(arrival_times[i]);
                continue;
            }
            // Need to check if element to be added is larger than top of stack.
            if(arrival_times[i] > groups.back()) {
                groups.push_back(arrival_times[i]);
            }

        }
        return groups.size();
    }
};
