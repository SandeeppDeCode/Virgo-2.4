/*
Given an integer array nums, sorted in ascending order (with distinct values) and a target value k. The array is rotated at some pivot point that is unknown. Find the index at which k is present and if k is not present return -1.

Certainly! Here’s a very concise note on how to narrow down the search in a rotated sorted array using binary search:

---

Narrowing Down the Search

1. Identify Sorted Half: Determine if the left or right half of the array is sorted.
2. Check Target Range:
   - If the left half is sorted and the target lies within that range, search the left half.
   - If the right half is sorted and the target lies within that range, search the right half.
3. Adjust Pointers: Update `low` and `high` pointers based on where to search next.

---



*/

#include <bits/stdc++.h>
using namespace std;
int search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;

    // Applying binary search algorithm
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // Check if mid points to the target
        if (nums[mid] == target)
            return mid;

        // Check if the left part is sorted
        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target <= nums[mid])
            {
                // Target exists in the left sorted part
                high = mid - 1;
            }
            else
            {
                // Target does not exist in the left sorted part
                low = mid + 1;
            }
        }
        else
        {
            // Check if the right part is sorted
            if (nums[mid] <= target && target <= nums[high])
            {
                // Target exists in the right sorted part
                low = mid + 1;
            }
            else
            {
                // Target does not exist in the right sorted part
                high = mid - 1;
            }
        }
    }
    // If target is not found
    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int result = search(nums, target);

    if (result == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << result << "\n";

    return 0;
}