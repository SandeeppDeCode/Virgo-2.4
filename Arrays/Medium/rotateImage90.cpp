/*
Problem - Rotate Image 90 degrees clockwise

Brute - Observe the pattern where rows become columns (transposed) and reverse the order of columns.
*/
#include <bits/stdc++.h>
using namespace std;

// Optimal rotation (in-place)
void rotateOptimal(vector<vector<int>>& arr) {
    int row = arr.size();
    int col = arr[0].size();

    // Step 1: Transpose the matrix
    for (int i = 0; i < row; i++) {
        for (int j = i; j < col; j++) {  // Start `j` from `i` to avoid redundant swaps
            swap(arr[i][j], arr[j][i]);
        }
    }

    // Step 2: Reverse each row
    for (int i = 0; i < row; i++) {
        reverse(arr[i].begin(), arr[i].end());
    }
}

// Rotation using an additional matrix
void rotate(vector<vector<int>>& arr) {
    int n = arr.size();
    vector<vector<int>> ans(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[j][n - 1 - i] = arr[i][j];
        }
    }

    // Copy back the rotated matrix to the original array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = ans[i][j];
        }
    }
}

int main() {
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Using the optimal in-place function
    rotateOptimal(arr);

    // Print the rotated matrix
    cout << "Rotated Image:" << endl;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

