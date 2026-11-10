class Solution {
public:
    // Assumes both words are the same size.
    // Returns if word1 can be converted to word2 and vice versa.
    bool valid_step(string word1, string word2) {
        int diff_count = 0;
        for(int i = 0; i < word1.size(); i++) {
            if(word1[i] != word2[i]) diff_count++;
        }
        return (diff_count == 1);
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // You can make a step if the word is the SAME except for one letter.
        // You need to find the minimum steps to find endWord starting from beginWord.
        // You can do a BFS starting from the begin word, with neighbors equal to
        // the words in wordlist that you can take a step to. 

        // Lets break this down. How do we find a valid word that we can take a step to?
        // Element-Wise, you can iterate across the characters of the word. This might 
        // be slow, since for every step you have to repeat this. 

        // Maybe pre-compute this. For words in word list, you can create an
        // adj list for what connects to what. This defines what steps you can 
        // take in your traversal. Create a mapping, of i: j
        // Where word i can be transformed to word j. And vice versa,
        // ["bat","bag","sag","dag","dot"]
        // 0: [1], 1: [0,2,3], 2: [1, 3], 3: [2,1], 4: []
        // Then you can find what beginWord maps to.

        // Creates adj list for word list.
        unordered_map<int,vector<int>> mapping;
                unordered_set<int> visited;
        queue<int> nodes;
        int end_idx = -1;
        
        for(int i = 0; i < wordList.size(); i++) {
            if(wordList[i] == endWord) end_idx = i;
            
            if(valid_step(beginWord, wordList[i]) || beginWord == wordList[i]) {
                nodes.push(i);
                visited.insert(i);
                //cout << i << endl;
            }
            //cout << i << endl;
            for(int j = 0; j < wordList.size(); j++) {
                // [word1,word2,word3]
                if(i == j) continue;
                if(valid_step(wordList[i], wordList[j])) {
                    // This means that i can be mapped to j
                    //cout << j << endl;
                    mapping[i].push_back(j);
                }
            }
        }
        if(end_idx == -1) return 0;

        // Now we can do a traversal. Each level of depth counts as a step.
        // Need to ensure you dont revisit ancestors.


        //cout << end_idx << endl;
        int min_steps = 2;
        while(!nodes.empty()) {
            int q_size = nodes.size();
            

            for(int i = 0; i < q_size; i++) {
                auto node = nodes.front();
                nodes.pop();
                
                if(node == end_idx) return min_steps;

                for(int nei:mapping[node]) {
                    // Need to ignore parent.
                    if(visited.find(nei) != visited.end()) continue;
                    
                    visited.insert(nei);

                    nodes.push(nei);
                }
            }
            min_steps++;
        }

        return 0;

    }
};
