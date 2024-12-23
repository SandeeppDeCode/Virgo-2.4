/*
Upper Bound:
Given a sorted array of nums and an integer x, write a program to find the upper bound of x. The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than a given key i.e. x.

If no such index is found, return the size of the array.

//Algo
Finds the smallest index with nums[mid] > x using binary search. If nums[mid] > x, update ans and search left (high = mid - 1), otherwise search right (low = mid + 1).
eg: [1,2,3,3,7,8,9,9,9,11];
*/

#include <bits/stdc++.h>
using namespace std;
int upperBound(vector<int> &nums, int x){
    int ans = nums.size();
    int low = 0;
    int high = nums.size() - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(nums[mid] > x){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {3, 5, 8, 9, 15, 19};
    int x = 9;

    int ind = upperBound(nums, x);

    cout << "The upper bound is the index: " << ind << "\n";

    return 0;
}