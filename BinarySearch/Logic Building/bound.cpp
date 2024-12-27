#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> nums = {1, 2, 4, 5, 6};
    int target = 4;

    // Use lower_bound to find the first position of target or greater
    auto it = lower_bound(nums.begin(), nums.end(), target);
    
    // Convert iterator to index
    int index = (it != nums.end()) ? (it - nums.begin()) : -1; // -1 if not found

    if (index != -1 && nums[index] == target) {
        cout << "The first occurrence of " << target << " is at index: " << index << endl;
    } else {
        cout << target << " not found in the array." << endl;
    }

    return 0;
}
