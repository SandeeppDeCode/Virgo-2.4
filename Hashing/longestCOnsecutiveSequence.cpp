/*
Problem: 
Given an array nums of n integers, return the length of the longest sequence of consecutive integers. The integers in this sequence can appear in any order.

Approaches:
1. **Optimal Solution** (using Hash Set):
   - Use an unordered set to store unique elements.
   - For each number, check if it is the start of a sequence (i.e., `num - 1` is not in the set).
   - Count consecutive numbers and update the longest streak.

2. **Better Solution** (using Sorting):
   - Sort the array first.
   - Traverse through the sorted array and count consecutive numbers.
   - Handle duplicates and update the longest streak accordingly.

3. **Brute Force**:
   - For each number, use linear search to find consecutive numbers.
   - Count the length of each sequence found, but this approach is inefficient (O(n^2)).

Note: The optimal solution has a time complexity of O(n) and does not modify the input array.
*/
#include<bits/stdc++.h>
using namespace std;


int longestConsecutiveOptimal(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end()); // Store unique elements in a set
    int longestStreak = 0;

    for (int num : numSet) {
        // Check if it's the start of a sequence
        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int currentStreak = 1;

            // Count streak
            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum++;
                currentStreak++;
            }

            longestStreak = max(longestStreak, currentStreak);
        }
    }

    return longestStreak;
}
//better - using sorting
int longestConsecutiveBetter(vector<int>& nums){
    sort(nums.begin(),nums.end());
    int longest = 1;
    int lastSmaller = INT_MIN;
    int count = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] - 1 == lastSmaller){
            count += 1;
            lastSmaller = nums[i];
        }else if (nums[i] == lastSmaller){
            //duplicate
        }else if (nums[i] != lastSmaller){
            //new begining 
            count = 1;
            lastSmaller = nums[i];
        }
        longest = max(longest,count);
    }
    return longest;
}

bool linearSearch(vector<int>& a, int num) {
    int n = a.size(); 

    for (int i = 0; i < n; i++) {
        if (a[i] == num)
            return true;
    }
    return false;
}
//brute 
int longestConsecutive(vector<int>& nums) {
    // sort(nums.begin(),nums.end());
    int maxLen = 0;
    for(int i = 0; i < nums.size();i++){
        int x = nums[i];
        int count = 1;
        while(linearSearch(nums,x+1)){
            x++;
            count++;
        }
        maxLen = max(maxLen,count);
    }
    return maxLen;
}
int main() {
    vector<int> a = {102,4,100,1,101,3,2,1,1,5}; 

    // Function call for finding longest consecutive sequence
    int ans = longestConsecutiveBetter(a); 
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}
