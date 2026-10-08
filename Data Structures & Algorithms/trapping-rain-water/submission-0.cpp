class Solution {
public:
    int trap(vector<int>& height) {

        // Find formula for water trapped at position i.
        // Its equal to the min(highest wall to the left, highest wall to the right) - 
        // current height of wall

        // At any position, we want to know the the maximum value to the left (prefix)
        // and maximum value to the right (suffix). Then at any position we can know the 
        // maximum value. 

        vector<int> prefix_max(height.size());
        vector<int> suffix_max(height.size());

        int pref_max;
        int suff_max;

        //[1,2,3,4]
        // Pref: [1, 2, 3, 4]
        // Suf:  [4, 4, ,4  4]

        for(int i = 0; i < height.size(); i++) {
            if(i == 0)  {
                pref_max = height[i];
                suff_max = height[height.size() - 1];
            }
            else {
                pref_max = max(pref_max, height[i]);
                suff_max = max(suff_max, height[height.size() - 1 - i]);
            }
            prefix_max[i] = pref_max;
            suffix_max[height.size() - 1 - i] = suff_max;
            //cout << suff_max << endl;
        }

        int water_collected = 0;
        for(int i = 0; i < height.size(); i++) {
            int water = min(prefix_max[i], suffix_max[i]) - height[i];
            if(water < 0) water = 0;

            water_collected+=water;
        }

        return water_collected;
        

    }
};
