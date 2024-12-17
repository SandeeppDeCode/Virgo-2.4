#include <bits/stdc++.h>
using namespace std;

//Optmimal Way
int missingNumber3(vector<int>&nums){
    int n = nums.size();
    int sumN = (n*(n + 1) )/ 2;
    int arrSum = 0;
    for(int i = 0; i < nums.size(); i++){
        arrSum += nums[i];
    }
    return sumN-arrSum;

}
//Better way
int missingNumber2(vector<int>& nums) {
    int n = nums.size();
    vector<int> freq(n + 1, 0); 
    for (int num : nums) {
        freq[num]++;
    }
    for (int i = 0; i <= n; i++) {
        if (freq[i] == 0) {
            return i;
        }
    }

    return -1;
}

// Brute Force Method
int missingNumber1(vector<int>& nums) {
    /*
    Time: O(N^2);
    Space: O(1);
    */
    for (int i = 0; i <= nums.size(); i++) {
        bool found = false;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == i) {
                found = true;
                break;
            }
        }
        if (!found) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {0, 1, 2, 4, 5, 6}; // Example input

    // Test both methods
    cout << "Missing number using frequency array: " << missingNumber2(nums) << endl;
    cout << "Missing number using brute force: " << missingNumber1(nums) << endl;
    cout << "Missing number using brute force: " << missingNumber3(nums) << endl;

    return 0;
}
