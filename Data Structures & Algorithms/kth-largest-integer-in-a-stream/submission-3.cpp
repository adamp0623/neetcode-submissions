#include <queue> 

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int k_largest;
public:
    KthLargest(int k, vector<int>& nums) {
        k_largest = k;
        // Should only add the largest nums. 
        for(int num : nums) {
            min_heap.push(num);
            if(min_heap.size() > k) min_heap.pop();
        }
    }
    
    int add(int val) {
        
        min_heap.push(val);
        if(min_heap.size() > k_largest) min_heap.pop();

        return min_heap.top();
    }
};
