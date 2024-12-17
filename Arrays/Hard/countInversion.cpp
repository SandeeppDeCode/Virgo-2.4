//Problem : 
/*
Given an integer array nums. Return the number of inversions in the array.



Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

It indicates how close an array is to being sorted.
A sorted array has an inversion count of 0.
An array sorted in descending order has maximum inversion.
*/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    /* Merge function to count 
    inversions and merge sorted halves*/
    long long int merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        long long int cnt = 0;

        // Merge sorted halves into temp array
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                // Count inversions
                cnt += (mid - left + 1);
                right++;
            }
        }

        // Copy remaining elements of left half
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        // Copy remaining elements of right half
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // Copy elements from temp array back to original array
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return cnt;
    }
    
    // Merge sort function to recursively sort and count inversions
    long long int mergeSort(vector<int>& arr, int low, int high) {
        long long int cnt = 0;
        if (low < high) {
            int mid = low + (high - low) / 2;
            
            // Sort left half
            cnt += mergeSort(arr, low, mid);  
            
            // Sort right half
            cnt += mergeSort(arr, mid + 1, high); 
            
            // Merge and count inversions
            cnt += merge(arr, low, mid, high);  
        }
        return cnt;
    }
    
public:
    // Function to find number of inversions in an array using merge sort
    long long int numberOfInversionsOptimized(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }

    // Function to find number of inversions in an array using brute force
    long long int numberOfInversionsBruteForce(vector<int>& nums) {
        long long int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] > nums[j]) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    vector<int> nums = {5, 4, 3, 2, 1};
    
    // Create an instance of Solution class
    Solution sol;

    // Using optimized approach
    long long resultOptimized = sol.numberOfInversionsOptimized(nums);
    
    // Using brute-force approach
    long long resultBruteForce = sol.numberOfInversionsBruteForce(nums);
    
    // Print the number of inversions found by both methods
    cout << "The number of inversions using optimized approach is: " << resultOptimized << endl;
    cout << "The number of inversions using brute-force approach is: " << resultBruteForce << endl;
    
    return 0;
}
