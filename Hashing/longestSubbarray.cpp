/*
Problem: 
Given an array nums of n integers and an integer target, return the length of the longest contiguous subarray whose sum equals target.

Approaches:
1. **Optimal Solution** (using Hash Map):
   - Maintain a cumulative sum and map it to its index.
   - If the cumulative sum equals the target, update maxLen.
   - If `cumSum - target` exists in the map, update maxLen using the difference of indices.
   - Time complexity: O(n).

2. **Better Solution** (using Nested Loops):
   - For each starting index, calculate the sum of subarrays ending at each subsequent index.
   - Update maxLen if the sum equals the target.
   - Time complexity: O(n^2).

3. **Brute Force** (Generating all Subarrays):
   - Use three nested loops to generate all possible subarrays and calculate their sums.
   - Update maxLen if any subarray's sum equals the target.
   - Time complexity: O(n^3), inefficient for large arrays.

Note: The optimal solution is preferred due to its linear time complexity and efficient use of space with a hash map.
*/

#include<bits/stdc++.h>
using namespace std;

int longestSubarrayOptimal(vector<int> &nums, int target) {
    unordered_map<int, int> sumIndexMap; // Maps cumulative sum 
    int cumSum = 0;
    int maxLen = 0;
    for(int i = 0; i < nums.size(); i++){
        cumSum += nums[i];
        if(cumSum == target)
        {
            maxLen = max(maxLen, i+1);
        }
        if(sumIndexMap.find(cumSum - target) != sumIndexMap.end()){
            maxLen = max(maxLen, i - sumIndexMap[cumSum - target]);
        }
        if(sumIndexMap.find(cumSum-target) == sumIndexMap.end()){
            sumIndexMap[cumSum] = i;
        }
    }
    return maxLen;

}

//better
int longestSubarrayBetter(vector<int> &nums, int target){
    int maxLen = 0;
    for(int i = 0; i < nums.size(); i++){
        int sum = 0;
        for(int j = i; j < nums.size(); j++){

                sum += nums[j];
                
            if(sum == target) maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}
//brute - genrate all the subarray
int longestSubarray(vector<int> &nums, int target){
    int maxLen = 0;
    for(int i = 0; i < nums.size(); i++){
        for(int j = i; j < nums.size(); j++){
            int sum = 0;
            for(int k = i; k <= j; k++){
                sum += nums[k];
                
            }
            if(sum == target) maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}

int main()
{
    vector<int> a = { 10, 5, 2, 7, 1, 9};
    int k = 15;

    int len = longestSubarrayOptimal(a, k);
    
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}