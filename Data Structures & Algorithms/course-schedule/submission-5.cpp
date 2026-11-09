class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // The prerequisites is essentially a directed graph.
        // Say you need to take 4 courses (0 to 3), 0 -> 1 -> 2 -> 3 is the graph,
        // and prereq describes the connections.
        // [1, 0] [2, 1] [3, 2] [3,1] [3,2] Would describe these prequistes. 
        // To figure out if you can complete all the courses, you need to pick the right
        // starting point so that you traverse the whole graph. Say you start at 3.
        // Find three in the prerequistes first element, and is says you need to take 2
        // and then 2 needs 1, and then 1 needs 0. 

        // You can do this exploration for every course and see if you can
        // traverse numCourses deep. Stop traversal if you already visisted a course
        // (this indicates a circular dependency) return false right away.


        unordered_map<int,vector<int>> mapping; 
        for(int i = 0; i < prerequisites.size(); i++) {
            auto prereq = prerequisites[i];
            mapping[prereq[1]].push_back(prereq[0]);

        }

        // 0 = unvisited, 1 = active on current path, 2 = finished
        vector<int> state(numCourses, 0);

        for (int course = 0; course < numCourses; course++) {
            if (state[course] == 2) continue;

            // {course, exiting}
            vector<pair<int, bool>> nodes;
            nodes.push_back({course, false});

            while (!nodes.empty()) {
                auto [node, exiting] = nodes.back();
                nodes.pop_back();

                if (exiting) {
                    state[node] = 2;
                    continue;
                }

                if (state[node] == 1) return false; // Back to an ancestor
                if (state[node] == 2) continue;     // Already checked safely

                state[node] = 1;

                // Stack is LIFO: process neighbors BEFORE finishing this node.
                nodes.push_back({node, true});

                for (int neighbor : mapping[node]) {
                    nodes.push_back({neighbor, false});
                }
            }
        }

        return true; // Every component was checked without finding a cycle
        
    }
};
