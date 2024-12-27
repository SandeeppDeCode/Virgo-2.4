/*
Given an integer array nums, sorted in ascending order (may contain duplicate values) and a target value k. Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False.
*/

#include <bits/stdc++.h>
using namespace std;

bool searchInARotatedSortedArrayII(vector<int> &arr, int k)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {

        int mid = (low + high) / 2;
        // Check if mid points to the target
        if (arr[mid] == k)
            return true;

        // Handle duplicates: if arr[low], arr[mid], and arr[high] are equal
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low = low + 1;
            high = high - 1;
            continue;
        }

        if (arr[low] <= arr[mid])
        {
            /*  Eliminate the right part if k
                exists in the left sorted part */
            if (arr[low] <= k && k <= arr[mid])
            {
                high = mid - 1;
            }
            // Otherwise eliminate the left part
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            /*  If the right part is sorted and
                k exists in the right sorted
                part, eliminate the left part   */
            if (arr[mid] <= k && k <= arr[high])
            {
                low = mid + 1;
            }
            // Otherwise eliminate the right part
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
}
int main()
{
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int target = 3;

    // Function call to search for the target element
    bool result = searchInARotatedSortedArrayII(arr, target);

    if (!result)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array.\n";

    return 0;
}