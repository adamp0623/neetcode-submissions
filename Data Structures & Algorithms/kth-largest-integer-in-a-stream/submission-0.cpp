class KthLargest {
    priority_queue<int> max_heap;
    int k_largest;
public:
    KthLargest(int k, vector<int>& nums) {
        k_largest = k;
        for(int num: nums) {
            max_heap.push(num);
        }
    }
    
    int add(int val) {
        max_heap.push(val);
        // Then need to return kth largest. You can pop 
        vector<int> popped_vals;
        // [2]
        // [1] want second largest. 
        for(int i = 0; i < k_largest - 1; i++) {
            popped_vals.push_back(max_heap.top());
            max_heap.pop();
        }
        int res = max_heap.top();

        for(int popped:popped_vals) {
            max_heap.push(popped);
        }

        return res;
    }
};
