/*
Given an integer array nums of size N, sorted in ascending order with distinct values, and then rotated an unknown number of times (between 1 and N), find the minimum element in the array.

*/
#include<bits/stdc++.h>
using namespace std;
int findMin(vector<int> &nums)  {
    int mini = INT_MAX;
    int low = 0;
    int high = nums.size() - 1;
    while(low <= high){
        int mid = (low + high) / 2;

        if(nums[low] <= nums[mid]){
            mini = min(nums[low],mini);
            low = mid + 1;
        }else{
            mini = min(nums[mid],mini);
            high = mid - 1;
        }
    }
    return mini;
}
int main() {
      
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3}; 
    
    // Create an object of the Solution class

    int ans = findMin(arr);   
    
    //Print the result
    cout << "The minimum element is: " << ans << "\n"; 
    return 0;  
}
