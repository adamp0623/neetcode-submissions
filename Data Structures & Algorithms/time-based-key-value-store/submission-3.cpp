class TimeMap {
    unordered_map<string, vector<pair<int,string>>> time_val;
public:
    TimeMap() {
        
    }
    
    // Stores a key with value at a timestamp.
    // We need to store the value keyed by a value and a timestamp.
    void set(string key, string value, int timestamp) {
        time_val[key].push_back({timestamp,value});
    }
    
    // We need to get the value of a key with timestamp_prev <= timestamp
    // For a given key, there should be a list of value, timestamp pairs.
    // Since each set adds <value,timestamp> pairs in non decreasing 
    // timestamp values, you can do a binary search on the timestamps,
    // and find the timestamp value that is the largest timestamp less than 
    // or equal to the timestamp.

    // If the time_val at the key is not empty, then check if the first value
    // is after the queried timestamp. If so, there are no values to return

    string get(string key, int timestamp) {
        if(time_val.find(key) == time_val.end()) return "";
        else if(time_val[key].front().first > timestamp) return "";

        // So now we have to conduct a binary search on the vector of 
        // <time,value> pairs by time, to find a time
        // <1, 'hi'>,<3, 'ho'>, <5, 'lo'>
        // <1, 'happy'> <2, 'sad'>

        int left = 0;
        int right = time_val[key].size() - 1;
        string candidate = "";

        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(time_val[key][mid].first <= timestamp) {
                candidate = time_val[key][mid].second;
                left = mid + 1;
            }
            else if(time_val[key][mid].first > timestamp) right = mid - 1;
        }
        return candidate;
    }
};
