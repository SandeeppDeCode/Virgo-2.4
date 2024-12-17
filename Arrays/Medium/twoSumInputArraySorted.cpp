/*
TWO SUM : IF the array input is sorted;
// we can use two pointer approach;
if(sum == target) got ans
if(sum > target) rigth--;
if(sum < targert) left--;
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    for(int num : nums){
        cout<< num << " ";
    }
    cout<<endl;
    int left = 0;
    int right = nums.size() - 1;

    while(left < right){
        int sum = nums[left] + nums[right];
        if(sum == target) return {left,right};
        else if(sum > target) right--;
        else if(sum < target) left++;
    }
    return {-1,-1};
}
int main(){
    int n = 5;
    vector<int> nums = {2, 6, 5, 8, 11};
    sort(nums.begin(),nums.end());
    int target = 14;
    


    
    // Call the twoSum method to find the indices
    vector<int> ans = twoSum( nums, target);
    
    // Print the result
    cout << "This is the answer: [" << ans[0] << ", " << ans[1] << "]" << endl;
    
    return 0;
}