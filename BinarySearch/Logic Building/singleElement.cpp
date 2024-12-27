/*
Problem :
Given an array nums sorted in non-decreasing order. Every number in the array except one appears twice. Find the single number in the array.

Note:
(even Odd) - element is on right half - eleminate left
(odd Even) - element on the left half - elimniate right half
*/
#include <bits/stdc++.h>
using namespace std;

/* Function to find the single non
duplicate element in a sorted array*/
int singleNonDuplicateOptimal(vector<int> &nums)
{
    int n = nums.size(); // Size of the array.

    // Edge cases:
    if (n == 1)
        return nums[0];
    if (nums[0] != nums[1])
        return nums[0];
    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // If nums[mid] is the single element:
        if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
        {
            return nums[mid];
        }

        // We are in the left part:
        if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
        {
            // Eliminate the left half:
            low = mid + 1;
        }
        // We are in the right part:
        else
        {
            // Eliminate the right half:
            high = mid - 1;
        }
    }

    // Dummy return statement:
    return -1;
}
int singleNonDuplicateBrute(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == 0)
        {
            if (nums[i] != nums[i + 1])
                return nums[0];
        }
        else if (i == nums.size() - 1)
        {
            if (nums[nums.size() - 1] != nums[nums.size() - 2])
                return nums[nums.size() - 1];
        }
        else
        {
            if (nums[i] != nums[i + 1] && nums[i] != nums[i - 1])
                return nums[i];
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 1, 2};
    int ans = singleNonDuplicateBrute(nums);

    cout << "The single element is: " << ans << "\n";

    return 0;
}