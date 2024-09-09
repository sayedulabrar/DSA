class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;

        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        while (top <= bottom && left <= right) {
            // Traverse top row
            for (int i = left; i <= right; ++i)
                result.push_back(matrix[top][i]);
            ++top;

            // Traverse right column
            for (int i = top; i <= bottom; ++i)
                result.push_back(matrix[i][right]);
            --right;

            // Traverse bottom row
            if (top <= bottom) { // Check if there are still rows to traverse
                for (int i = right; i >= left; --i)
                    result.push_back(matrix[bottom][i]);
                --bottom;
            }

            // Traverse left column
            if (left <= right) { // Check if there are still columns to traverse
                for (int i = bottom; i >= top; --i)
                    result.push_back(matrix[i][left]);
                ++left;
            }
        }

        return result;
    }
};






class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Transpose the matrix
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row
        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

Initial matrix:
1 2 3 
4 5 6 
7 8 9 

After transposition:
1 4 7 
2 5 8 
3 6 9 

After reversing each row:
7 4 1 
8 5 2 
9 6 3 








Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.

we use 1st row and col as marker.But we can not ake 1st row and col entirely 0 as it will turn everythin 0.That's why we used 2 bool to track if 1st col and row will become completely 0.And we go through 1 to m and 1 to n and if 0 encountered mark it in 1st row and col in that index.This way we will be able to make the correct rows and cols 0.Then at the end as the work as marker is finished we will turn the 1st row,col to 0 based on 2 bool.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRowZero = false;
        bool firstColZero = false;

        // Check if first row contains zero
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // Check if first column contains zero
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // Mark rows and columns to be zeroed based on non-zero elements
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) { 
                those which are 0 will remain 0 and those which are newly marked will also be 0
                but no problem as for both case it will be entire row,col 0.
                
                    matrix[i][0] = 0; // Mark the corresponding row to be zeroed
                    matrix[0][j] = 0; // Mark the corresponding column to be zeroed
                }
            }
        }

        // Set rows to zero based on marks in the first column
        for (int i = 1; i < m; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Set columns to zero based on marks in the first row
        for (int j = 1; j < n; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Set first row to zero if needed
        if (firstRowZero) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }

        // Set first column to zero if needed
        if (firstColZero) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};