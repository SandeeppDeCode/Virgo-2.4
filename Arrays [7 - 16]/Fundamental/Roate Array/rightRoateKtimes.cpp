/*
// // Step 1: Reverse the last k elements
// // Step 2: Reverse the first n-k elements
// // Step 3: Reverse the entire array
    nums = [1,2,3,4,5] k = 2;

    last k element = [1,2,3,5,4];
    first n - k element = [3,2,1,5,4];
    reverse the whole array = [4,5,1,2,3]

*/
#include<bits/stdc++.h>
using namespace std;

vector<int>rightRotateKtimes(vector<int>nums,int k){
    int n = nums.size();
    k = k % n;

    reverse(nums.end() - k, nums.end());
    reverse(nums.begin(),nums.end() - k );
    reverse(nums.begin(), nums.end());
    return nums;
}
int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2; // Number of rotations
    nums = rightRotateKtimes(nums, k);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}