/*
Problem :- 
Given an integer array nums of size n containing values from [1, n] and each value appears exactly once in the array, except for A, which appears twice and B which is missing.


Optimal Approach
-Traverse through the array.
    -For each number, calculate its corresponding index (using absolute value to handle already marked indices).
    -If the number at that index is negative, it indicates that the number has been seen before (this is our repeating number).
    -If it's positive, mark it as seen by negating the number at that index.
    -After processing, traverse through the array again to find the missing number (the index of the positive number
*/


#include<bits/stdc++.h>
using namespace std;

//OPTMIAL 

vector<int> findMissingRepeatingNumbersOptimal(vector<int>& nums) {
    int n = nums.size();
    int repeating = -1, missing = -1;

    // First pass to find the repeating number
    for (int i = 0; i < n; i++) {
        int index = abs(nums[i]) - 1; // Get index corresponding to nums[i]
        if (nums[index] < 0) {
            // If it's negative, we found our repeating number
            repeating = abs(nums[i]);
        } else {
            // Mark as visited by negating
            nums[index] = -nums[index];
        }
    }

    // Second pass to find the missing number
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            // The index + 1 is the missing number
            missing = i + 1;
            break;
        }
    }

    return {repeating, missing};
}
//better - using hashing

vector<int> findMissingRepeatingNumbersBetter(vector<int> nums) {
    int n = nums.size();

    vector<int>hash(n+1,0);
    for(int i = 0; i < nums.size(); i++){
        hash[nums[i]]++;
    }
    for(int num : hash){
        cout<<num<<" ";
    }
    int missing = -1, repeating = -1;

    for(int i = 1; i < hash.size(); i++){
        if(hash[i] == 0) missing = i;
        if(hash[i] == 2) repeating = i;
    }
    return {missing,repeating};
}
//brute - linear search
vector<int> findMissingRepeatingNumbers(vector<int> nums) {
    int n = nums.size();
    int repeating = -1, missing = -1;
    for(int i = 1; i <= n; i++){
        int count = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] == i){
                count++;
            }
        }
        if(count == 2) repeating = i;
        if(count == 0) missing = i;
    }
    return {missing,repeating};
}
int main(){
    vector<int> nums = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> result = findMissingRepeatingNumbersBetter(nums);
    
    // Print the repeating and missing numbers found
    cout << "The repeating and missing numbers are: {" << result[0] << ", " << result[1] << "}\n";
    
    return 0;
}
