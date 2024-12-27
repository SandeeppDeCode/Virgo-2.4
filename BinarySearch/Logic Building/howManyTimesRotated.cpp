/*
Given an integer array nums of size n, sorted in ascending order with distinct values. The array has been right rotated an unknown number of times, between 1 and n. Determine the number of rotations performed on the array.
*/
#include<bits/stdc++.h>
using namespace std;

vector<int>findKRotation(vector<int> &nums)  {
    int low = 0, high = nums.size() - 1;
    int mini = INT_MAX;
    int index = -1;
    while(low <= high){
        int mid = (low + high) / 2;
            /* Search space is already sorted
            then nums[low] will always be
            the minimum in that search space */
            if (nums[low] <= nums[high]) {
                if (nums[low] < mini) {
                    index = low;
                    mini = nums[low];
                }
                break;
            }
        //left sorted;
        if(nums[low] <= nums[mid]){
                if (nums[low] < mini) {
                    index = low;
                    mini = nums[low];
                }
                // Eliminate left half
                low = mid + 1;
        }else{
            //right portion sorted;
            if(nums[mid] < mini){
                index = mid;
                mini = nums[mid];
            }
            high = mid - 1;
        }
    }
    return {index,mini};
}
int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2, 3}; 
    

    
    vector<int>ans = findKRotation(nums);
    
    // Print the result
    cout << "The array is rotated " << ans[0] << " " <<ans[1]<< " times.\n";
    
    return 0;
}