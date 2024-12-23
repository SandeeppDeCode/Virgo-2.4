
/*
Problem: 
Given an array nums of n integers and an integer k, return the total number of contiguous subarrays whose sum equals k.

Approaches:
1. **Optimal Solution** (using Hash Map):
   - Maintain a hash map to store the frequency of prefix sums.
   - For each element, update the cumulative sum and check if `cumulativeSum - k` exists in the map.
   - If it exists, increment the count by the number of occurrences of that sum.
   - Time complexity: O(n).

2. **Better Solution** (using Nested Loops):
   - Use two nested loops to calculate the sum of all possible subarrays.
   - Increment the count whenever the current sum equals k.
   - Time complexity: O(n^2).

3. **Brute Force**:
   - Use three nested loops to generate all possible subarrays and calculate their sums.
   - Increment the count if any subarray's sum equals k.
   - Time complexity: O(n^3), inefficient for larger arrays.

Note: The optimal solution is preferred due to its linear time complexity and efficient use of space with a hash map.
*/

#include <bits/stdc++.h>
using namespace std;

int subarraySumOptimal(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumCount; // Map to store prefix sums and their counts
    prefixSumCount[0] = 1; // Base case: one way to have a sum of zero (no elements)
    
    int cumulativeSum = 0; 
    int count = 0; 

    for (int num : nums) {
        cumulativeSum += num; // Update cumulative sum
        
        // Check if there is a previous cumulative sum that would give us the desired sum
        if (prefixSumCount.find(cumulativeSum - k) != prefixSumCount.end()) {
            count += prefixSumCount[cumulativeSum - k]; // Increment count by the number of times this sum has occurred
            //If it exists, it means there are some previous subarrays that, when combined with the current subarray, will give us a total sum of k

        }

        // Update the frequency of the current cumulative sum in the map
        prefixSumCount[cumulativeSum]++;
    }
    
    return count; // Return the total count of subarrays
}

//Better usign prefixSum
int subarraySumBetter(vector<int> &nums, int k)
{
        int n = nums.size(); 
        // Number of subarrays
        int count = 0;

        // starting index
        for (int startIndex = 0; startIndex < n; startIndex++) { 
            int currentSum = 0;
            // ending index
            for (int endIndex = startIndex; endIndex < n; endIndex++) { 
                // calculate the sum of subarray [startIndex...endIndex]
                // sum of [startIndex..endIndex-1] + nums[endIndex]
                currentSum += nums[endIndex];

                // Increase the count if currentSum == k:
                if (currentSum == k)
                    count++;
            }
        }
    return count;
}

//BruteForce --
int subarraySumBrute(vector<int> &nums, int k)
{
        int n = nums.size();
        // Number of subarrays
        int cnt = 0;

        // starting index i
        for (int i = 0; i < n; i++) {
            // ending index j
            for (int j = i; j < n; j++) {

                // calculate the sum of subarray [i...j]
                int sum = 0;
                for (int K = i; K <= j; K++)
                    sum += nums[K];

                // Increase the count if sum == k:
                if (sum == k)
                    cnt++;
            }
        }
        return cnt;
}
int main() {
    vector<int> nums = {2, -1, 2, -3, 4};
    int k = 3;

    int result = subarraySumOptimal(nums, k);
    cout << "Total number of subarrays whose sum equals " << k << ": " << result << endl;

    return 0;
}
