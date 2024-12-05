#include <bits/stdc++.h>
using namespace std;

// Selection Sort function
void selectionSort(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        int miniIndex = i; // Assume the current index has the minimum value
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] < nums[miniIndex]) {
                miniIndex = j; // Update the index of the smallest element
            }
        }
        // Swap only once after finding the minimum index
        if (miniIndex != i) {
            swap(nums[miniIndex], nums[i]);
        }
    }
}

int main() {
    vector<int> nums{7, 4, 1, 5, 3};
    selectionSort(nums);
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
