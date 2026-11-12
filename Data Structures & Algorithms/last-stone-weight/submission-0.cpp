class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_heap;
  for(int stone:stones) {
    max_heap.push(stone);
  }

  while(max_heap.size() > 1) {
    int stone1 = max_heap.top();
    max_heap.pop();
    int stone2 = max_heap.top();
    max_heap.pop();

    if(stone1 != stone2) max_heap.push(abs(stone1 - stone2)); 
  }

  if(max_heap.empty()) return 0;
  else return max_heap.top();
    }
};
