/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value. If the target is not found in the array, return [-1, -1].
*/

#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int first = -1;

    // Applying Binary Search Algorithm
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        /*  If the target element is found, we
            update the first variable to mid and
            eliminate the right half to look for
            more smaller index where target is present */
        if (nums[mid] == target)
        {
            first = mid;
            high = mid - 1;
        }

        /*  If middle element is smaller,
            we eliminate the left half  */
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }

        /*  If middle element is greater,
            we eliminate the right half  */
        else
        {
            high = mid - 1;
        }
    }
    return first;
}

// Function to find the last occurrence of the target
int lastOccurrence(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int last = -1;

    // Applying Binary Search Algorithm
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        /*  If the target element is found, we
            update the first variable to mid and
            eliminate the right half to look for
            more greater index where target is present */
        if (nums[mid] == target)
        {
            last = mid;
            low = mid + 1;
        }

        /*  If middle element is smaller,
            we eliminate the left half  */
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }

        /*  If middle element is greater,
            we eliminate the right half  */
        else
        {
            high = mid - 1;
        }
    }
    return last;
}
// using bound
vector<int> searchRangeBetter(vector<int> &nums, int target)
{
    // Find the lower bound (first occurrence)
    auto lower = lower_bound(nums.begin(), nums.end(), target);
    // Check if the target is found
    if (lower == nums.end() || *lower != target)
    {
        return {-1, -1}; // Target not found
    }

    // Find the upper bound (one past the last occurrence)
    auto upper = upper_bound(nums.begin(), nums.end(), target);

    // Calculate the indices
    int startIndex = lower - nums.begin();
    int endIndex = upper - nums.begin() - 1; // Last occurrence index

    return {startIndex, endIndex};
}

//brute - linerar search
    vector<int> searchRange(vector<int>& nums, int target)
    {
        // Initialize variables to store first and last occurrences
        int first = -1, last = -1;
        vector<int> ans;

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            // Check if current element is the target
            if (nums[i] == target) {
                if (first == -1)   first = i; 
                last = i; 
            }
        }

        // Store the results in the answer vector
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = searchRangeBetter(nums, target);

    cout << "The first and last occurrences are at indices: "
         << result[0] << " and " << result[1] << "\n";

    return 0;
}