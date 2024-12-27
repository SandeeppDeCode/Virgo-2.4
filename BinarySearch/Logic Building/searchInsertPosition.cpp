/*
Problem : 
Given a sorted array of nums consisting of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
*/

#include<bits/stdc++.h>
using namespace std;
int searchInsert(vector<int> &nums, int target)  {
    int ans = nums.size();
    int low = 0;
    int high = nums.size() - 1;

    while(low <= high){
        int mid = (low + high) / 2;
        
        if(nums[mid] >= target){
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
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    int ind = searchInsert(nums, target);

    cout << "The index is: " << ind << "\n";
    return 0;
}