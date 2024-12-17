/*
    Step 1: Reverse the first k elements
    Step 2: Reverse the remaining n-k elements
    Step 3: Reverse the entire array

    nums = [3, 4, 5, 1, 2]  k = 2;
    reverse first k elemnt = [4, 3, 5, 1, 2];
    revrse remaingng n - k (5 - 2 = 3) = [4,3,2,1,5];
    Reverse the entire array = [5,1,2,3,4]


    
    

*/
#include <bits/stdc++.h>
using namespace std;

void leftRotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; // Handle cases where k > n
    cout<<5 % 5<<endl;
    reverse(nums.begin(), nums.begin() + k);

    reverse(nums.begin() + k, nums.end());

    reverse(nums.begin(), nums.end());
}

int main() {
    vector<int> nums = {3, 4, 5, 1, 2};
    int k = 2; // Number of rotations
    leftRotate(nums, k);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}
