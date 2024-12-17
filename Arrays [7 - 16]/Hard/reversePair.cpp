//Problem : Reverse Pair
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Merge function to count reverse pairs during the merge process
    long long mergeAndCount(vector<int>& arr, int low, int mid, int high) {
        long long count = 0;
        int left = low;
        int right = mid + 1;

        // Count reverse pairs
        while (left <= mid && right <= high) {
            if (arr[left] > 2 * arr[right]) {
                count += (mid - left + 1); // All elements from left to mid form a reverse pair with arr[right]
                right++;
            } else {
                left++;
            }
        }

        // Merge the two halves
        vector<int> temp;
        left = low;
        right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left++]);
        }

        while (right <= high) {
            temp.push_back(arr[right++]);
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return count;
    }

    // Merge sort function to sort the array and count reverse pairs
    long long mergeSortAndCount(vector<int>& arr, int low, int high) {
        long long count = 0;
        if (low < high) {
            int mid = low + (high - low) / 2;

            count += mergeSortAndCount(arr, low, mid); // Count in left half
            count += mergeSortAndCount(arr, mid + 1, high); // Count in right half
            count += mergeAndCount(arr, low, mid, high); // Count reverse pairs during merging
        }
        return count;
    }

public:
    // Function to find number of reverse pairs in an array using merge sort
    long long numberOfReversePairsOptimized(vector<int>& nums) {
        return mergeSortAndCount(nums, 0, nums.size() - 1);
    }

    // Function to find number of reverse pairs in an array using brute force
    long long numberOfReversePairsBruteForce(vector<int>& nums) {
        long long count = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] > 2 * nums[j]) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    vector<int> nums = {4, 1, 2, 3, 1};
    
    // Create an instance of Solution class
    Solution sol;

    // Using optimized approach
    long long resultOptimized = sol.numberOfReversePairsOptimized(nums);
    
    // Using brute-force approach
    long long resultBruteForce = sol.numberOfReversePairsBruteForce(nums);
    
    // Print the number of reverse pairs found by both methods
    cout << "The number of reverse pairs using optimized approach is: " << resultOptimized << endl;
    cout << "The number of reverse pairs using brute-force approach is: " << resultBruteForce << endl;
    
    return 0;
}
