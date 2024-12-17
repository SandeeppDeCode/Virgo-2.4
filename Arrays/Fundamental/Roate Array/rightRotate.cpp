/*
Right rotate or clockwise; [1,2,3,4,5] 
                             \ \ \ \
                           [5,1,2,3,4] 
*/
#include<bits/stdc++.h>
using namespace std;

void rightRotate(vector<int>& nums) {
    int last = nums[nums.size() - 1]; // Store the last element
    for (int i = nums.size() - 1; i > 0; i--) {
        nums[i] = nums[i - 1]; // Shift elements one position to the right
    }
    nums[0] = last; // Place the last element at the first position
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    rightRotate(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}
