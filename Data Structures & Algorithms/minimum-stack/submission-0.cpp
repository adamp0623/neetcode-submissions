class MinStack {
    // Need to implement a stack, but need O(1) retrieval and state invariance for
    // the minimum value across the stack. 
    // A min-heap allows for O(1) retrieval of minimum value. 
    int cur_min;
    vector<pair<int,int>> min_stack;

    // Maybe store in the stack as a pair, what the value is and what the minimum was before
    // it was added.
    // <val, cur_min>
    // <1,1> <2,1> <0,1>
    // Cur min is 1, 1, 0
    // Pop <0,1>, remove this element, make new min equal to 1.
    // Top: <2,1>, cur_min = 1
    // <1,1> <2,1> <-1, 1>
public:
    MinStack() {
        
    }
    
    // Push a value onto the stack. Need to update min value if a new minimum value is added.
    void push(int val) {
        // If stack is empty, value added is the minimum.
        if(min_stack.empty()) {
            cur_min = val;
            min_stack.push_back({val, cur_min});
        }
        else if(val < cur_min) {
            // If the new val to be added is smaller than the current min
            min_stack.push_back({val, cur_min});
            cur_min = val;
        }
        else {
            // If the value to be added wont effect the min, just add to the stack.
            min_stack.push_back({val, cur_min});
        }
    }

   // Pop needs to remove the top value from the stack. If minimum value is being popped, 
   // need to update the minimum value. 
    void pop() {
        // If the value to be popped is the current minimum, make the current minimum
        // whatever the value was when it was added.
        if(min_stack.back().first == cur_min) {
            cur_min = min_stack.back().second;
            min_stack.pop_back();
        }
        else {
            min_stack.pop_back();
        }
        
    }
    
    // Needs to check the value at the top of the stack.
    int top() {
        return min_stack.back().first;
    }
    
    // Need to get the minimum value.
    int getMin() {
        return cur_min;
    }
};
