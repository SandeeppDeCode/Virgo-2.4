/*

Algorithm: Spiral Matrix Traversal
1. Initialize boundaries:
   - `top = 0`, `bottom = n-1`, `left = 0`, `right = m-1`.
2. Traverse in 4 directions in this order:
   a. Left-to-Right along `top` row, then increment `top`.
   b. Top-to-Bottom along `right` column, then decrement `right`.
   c. Right-to-Left along `bottom` row (if `top <= bottom`), then decrement `bottom`.
   d. Bottom-to-Top along `left` column (if `left <= right`), then increment `left`.
3. Repeat until boundaries overlap or cross.
4. Conditions `if (top <= bottom)` and `if (left <= right)` ensure no invalid access.

Time Complexity: O(m * n) (each element is visited once).
Space Complexity: O(1) (excluding output array).


*/

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans; 
    int n = matrix.size(); // no of rows
    int m = matrix[0].size(); // no of columns
    int top = 0, left = 0, bottom = n - 1, right = m - 1;

    // Loop until all boundaries are valid
    while (top <= bottom && left <= right) {

        // Traverse from left to right
        for (int i = left; i <= right; i++) {
            ans.push_back(matrix[top][i]);
        }
        top++; // Move top boundary down


        // Traverse from top to bottom
        for (int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--; // Move right boundary left


        // Traverse from right to left (if still within bounds)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--; // Move bottom boundary up
        }

        // Traverse from bottom to top (if still within bounds)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++; // Move left boundary right
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    // Get spiral order using the function
    vector<int> ans = spiralOrder(mat);

    cout << "Elements in spiral order are: ";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
