class Solution {
    unordered_map<int,vector<int>> mapping; 
    unordered_set<int> visiting;
    unordered_set<int> finished;
    vector<int> res;

    
public:
    bool dfs(int course) {
        if(visiting.find(course) != visiting.end()) return false;
        if(finished.find(course) != finished.end()) {
            return true;
        }
        visiting.insert(course);
        for(int pre:mapping[course]) {
            if(!dfs(pre)) return false;
        }
        visiting.erase(course);
        finished.insert(course);
        res.push_back(course);
        return true;

        
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        // If there is a cycle, you cant finish all the courses, so you
        // should return an empty list. 
        
        // [i,j]
        // Mapping
        // i: j
        
        for(int i = 0; i < prerequisites.size(); i++) {
            auto prereq = prerequisites[i];
            mapping[prereq[0]].push_back(prereq[1]);
        }

        // If there arent any cycles, append courses in the 
        // opposite direction that they were searched.
        // Say there is courses = 3 [1,0] [3,2]
        // Do a DFS on 3: 3->2->1->0, [0,1,2,3] is a valid ordering.
        // What if they are disconnected.
        // Say Num courses = 3: [1,0] [3,2] [3,1]
        // One needs 0, three needs two.
        // So a valid ordering is 1->0 [0,1,2,3] or [2,3,0,1]
        // So you can just append the result of each DFS to get a valid ordering.
        // But if a course depends on 2 courses, like [1,0] [3,2] [3,1]
        // Doing the DFS will give, 
        // 3->1->0 or 3->2->0 [0,1,3,0,2,3]
        // when it should be [0,1,2,3] or [0,2,1,3] 
        // 2 just needs to be before three. no matter where. 
        for(int i = 0; i < numCourses; i++) {
            if(!dfs(i)) return {};
            //if(res.size() == numCourses) return res;
        }

        return res;
        // [0,1] 1 -> 0

    }
};
