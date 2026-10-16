class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Original idea would be to flatten the matrix by going through every element
        // and creating one long vector of length m*n. Then doing a binary search on that
        // but that would be O(n*m + log(m*n)) = O(n*m). Not good enough.

        // Maybe we can iterate through only the first and last element in each row and check 
        // what the value is. 
        // If the target is greater than the first index, but smaller than the last index,
        // Do the binary search on that row. That gives O(n + log(m))
        
        // [1,2,4,8]
        // [10,11,12,13]
        // [14, 20, 30,40] target = 12 
        int n = matrix.size();
        int m = matrix[0].size();

        int left = 0;
        int right = n * m - 1;

        while(right >= left) {
            int mid = left + (right - left) / 2;
            
            if(matrix[mid / m][ mid % m] < target) {
                left = mid + 1;
            }
            else if(matrix[mid / m][ mid % m] > target) {
                right = mid - 1;
            }
            else {
                return true;
            }
        }

        return false;
        
    }
};
