#include <queue>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Maintain a max_heap that keeps track of the k largest points.
        // Then, the top of that heap contains the kth largest point.
        // As you add points to the heap, if the size of the heap exceeds k,
        // remove the smallest element. 
        // The heap needs to contain
        // What to include in the priority queue... <distance, index>
        priority_queue<pair<int,int>, vector<pair<int,int>>> max_heap;
        for(int i = 0; i < points.size(); i++) {
            int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            max_heap.push({dist,i});
            cout << dist << endl;
            cout << i << endl;
            if(max_heap.size() > k) {
                max_heap.pop();
            }
        }

        vector<vector<int>> res;
        while(!max_heap.empty()) {
            pair<int,int> point = max_heap.top();
            res.push_back(points[point.second]);
            max_heap.pop();
        }
        return res;
    }
};
